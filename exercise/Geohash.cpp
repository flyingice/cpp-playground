#include <iostream>
#include <string>
using namespace std;

const char base32[] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'b', 'c', 'd', 'e', 'f', 'g',
                        'h', 'j', 'k', 'm', 'n', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z' };

int increasePrecision(double target, double& low, double& high) {
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

string encode(double latitude, double longitude, int precision) {
  static const int WIDTH = 5;

  string geohash;
  double latitudeLow = -90, latitudeHigh = 90;
  double longitudeLow = -180, longitudeHigh = 180;
  int i = 0;
  int decimal = 0;
  int isLongitude = 1;
  while (geohash.size() < precision) {
    decimal <<= 1;
    decimal += (isLongitude ? increasePrecision(longitude, longitudeLow, longitudeHigh)
                            : increasePrecision(latitude, latitudeLow, latitudeHigh));
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

int main() {
  double longitude = 116.38954991, latitude = 39.92816697;
  int precision = 12;
  cout << encode(latitude, longitude, precision) << endl;
  return 0;
}