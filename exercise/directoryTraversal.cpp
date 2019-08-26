#include <algorithm>
#include <boost/filesystem.hpp>
#include <ctime>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
using namespace boost::filesystem;

time_t findLastWriteSubDirectory(const path& iAbsPath) {
  try {
    vector<directory_entry> v;
    copy_if(directory_iterator(iAbsPath), directory_iterator(), back_inserter(v), [](const directory_entry& e) {
      return is_directory(e);
    });

    /*
     * The following code won't work:
     * auto it = max_element(directory_iterator(iAbsPath), directory_iterator(), predicate);
     * since the directory_iterator shares state.
     */
    auto it = max_element(v.begin(), v.end(), [](const directory_entry& l, const directory_entry& r) {
      // Note that last_write_time() returns file mtime.
      // Linux doesn't record file creation time. Even for atime, it is not always up-to-date,
      // depending on the disk mount options. Please refer to
      // https://superuser.com/questions/464290/why-is-cat-not-changing-the-access-time
      return last_write_time(l) < last_write_time(r);
    });

    return it != v.end() ? last_write_time(*it) : 0;
  }
  catch (const filesystem_error&) {
    // Exception might be thrown for many reasons,
    // e.g. no access rights on the target path, path doesn't exist etc.
    cerr << "failed to access all the files within " << iAbsPath << endl;
    return 0;
  }
}

struct UnaryPredicate {
  UnaryPredicate(const string& iFilename) : filename(iFilename) {
  }

  bool operator()(const path& iPath) const {
    return iPath.filename() == filename;
  };

  string filename;
};

void traverseDirectoryRecursive(const path& iPath, UnaryPredicate p) {
  for (auto it = directory_iterator(iPath); it != directory_iterator(); it++) {
    if (is_directory(it->path())) {
      traverseDirectoryRecursive(it->path(), p);
    }
    else {
      if (p(*it)) cout << "found " << it->path().filename() << endl;
    }
  }
}

void traverseDirectory(const path& iPath) {
  for (auto it = recursive_directory_iterator(iPath); it != recursive_directory_iterator(); it++) {
    cout << it->path() << endl;
  }
}

int main() {
  const string target("/Users/rainforest/");
  time_t t = findLastWriteSubDirectory(target);
  cout << "The last write directory under " << target << " was updated on " << ctime(&t);

  traverseDirectoryRecursive("/Users/rainforest/Downloads", UnaryPredicate("rdv.pdf"));

  return 0;
}