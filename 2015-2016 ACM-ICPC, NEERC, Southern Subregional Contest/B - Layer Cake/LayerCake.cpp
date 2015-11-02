#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>

using namespace std;

struct Layer {
	int width;
	int height;

	unsigned long long area() {
		return  1ULL * width * height;
	}

	bool fitsIn(const Layer& oth) const {
		return (this->width <= oth.width && this->height <= oth.height) ||
			   (this->width <= oth.height && this->height <= oth.width);
	}

	bool operator<(const Layer& oth) const {
		return fitsIn(oth);
	}
};

int main() {
	#ifndef ONLINE_JUDGE
		ifstream cin("testinput.in");
	#endif

	int n;
	cin >> n;
	vector<Layer> layers(n);

	for(int i = 0; i < n; ++i) {
		cin >> layers[i].width >> layers[i].height;
	}

	sort(layers.begin(), layers.end());

	unsigned long long maxVolume = 0;
	Layer maxLayer;
	for(int i = 0; i < n; ++i) {
		Layer baseLayer = layers[i];

		unsigned long long volume = 0;

		for(int j = i; j < n; ++j) {
			if(baseLayer.fitsIn(layers[i])) {
				volume += layers[i].area();
			}
		}

		if(volume > maxVolume) {
			maxVolume = volume;
			maxLayer = baseLayer;
		}
	}
	cout << maxVolume << endl;
	cout << maxLayer.width << ' ' << maxLayer.height << endl;
}