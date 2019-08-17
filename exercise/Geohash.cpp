#include <iostream>
#include <string>
#include <unordered_map>
#include <utility>
using namespace std;

typedef double Latitude;
typedef double Longitude;

const char base32[] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'b', 'c', 'd', 'e', 'f', 'g',
                        'h', 'j', 'k', 'm', 'n', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z' };
unordered_map<char, int> base32Inverted = {
  { '0', 0 },  { '1', 1 },  { '2', 2 },  { '3', 3 },  { '4', 4 },  { '5', 5 },  { '6', 6 },  { '7', 7 },
  { '8', 8 },  { '9', 9 },  { 'b', 10 }, { 'c', 11 }, { 'd', 12 }, { 'e', 13 }, { 'f', 14 }, { 'g', 15 },
  { 'h', 16 }, { 'j', 17 }, { 'k', 18 }, { 'm', 19 }, { 'n', 20 }, { 'p', 21 }, { 'q', 22 }, { 'r', 23 },
  { 's', 24 }, { 't', 25 }, { 'u', 26 }, { 'v', 27 }, { 'w', 28 }, { 'x', 29 }, { 'y', 30 }, { 'z', 31 },
};

int increaseEncodePrecision(double target, double& low, double& high) {
  double mid = low + (high - low) / 2;
  if (target <= mid) {
    high = mid;
    return 0;
  }
  else {
    low = mid;
    return 1;
  }
}

double increaseDecodePrecision(int digit, double& low, double& high) {
  double mid = low + (high - low) / 2;
  if (digit == 0) {
    high = mid;
    return low + (mid - low) / 2;
  }
  else {
    low = mid;
    return mid + (high - mid) / 2;
  }
}

string encode(Latitude latitude, Longitude longitude, int precision) {
  static const int WIDTH = 5;

  string geohash;
  Latitude latitudeLow = -90, latitudeHigh = 90;
  Longitude longitudeLow = -180, longitudeHigh = 180;
  int i = 0;
  int decimal = 0;
  int isLongitude = 1;
  while (geohash.size() < precision) {
    decimal <<= 1;
    decimal += (isLongitude ? increaseEncodePrecision(longitude, longitudeLow, longitudeHigh)
                            : increaseEncodePrecision(latitude, latitudeLow, latitudeHigh));
    i++;
    isLongitude ^= 1;
    if (i == WIDTH) {
      i = 0;
      geohash += string(1, base32[decimal]);
      decimal = 0;
    }
  }

  return geohash;
}

pair<Latitude, Longitude> decode(const string& geohash) {
  static const int WIDTH = 5;

  Latitude latitude = 0;
  Longitude longitude = 0;
  Latitude latitudeLow = -90, latitudeHigh = 90;
  Longitude longitudeLow = -180, longitudeHigh = 180;
  int isLongitude = 1;
  for (int i = 0; i < geohash.size(); i++) {
    int decimal = base32Inverted[geohash[i]];
    for (int j = 0; j < WIDTH; j++) {
      int digit = (decimal >> (WIDTH - 1 - j)) & 0x1;
      if (isLongitude) {
        longitude = increaseDecodePrecision(digit, longitudeLow, longitudeHigh);
      }
      else {
        latitude = increaseDecodePrecision(digit, latitudeLow, latitudeHigh);
      }

      isLongitude ^= 1;
    }
  }

  return { latitude, longitude };
}

int main() {
  Longitude longitude = 116.38954991;
  Latitude latitude = 39.92816697;
  int precision = 12;
  cout << encode(latitude, longitude, precision) << endl;  // expected result "wx4g0s8q3jf9"

  auto coordinate = decode("wx4g0s8q3jf9");
  cout << "latitude: " << coordinate.first << ", longitude: " << coordinate.second << endl;

  return 0;
}