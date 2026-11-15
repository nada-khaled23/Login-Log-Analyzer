#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    vector<string> logs = {
        "192.168.1.10 FAILED",
        "10.0.0.5 SUCCESS",
        "192.168.1.10 FAILED",
        "172.16.0.2 FAILED",
        "192.168.1.10 FAILED",
        "10.0.0.5 FAILED",
        "192.168.1.10 FAILED"
    };

    vector<string> ips;
    vector<int> counts;

    for (int i = 0; i < logs.size(); i++) {
        int spacePos = logs[i].find(' ');
        string ip = logs[i].substr(0, spacePos);
        string status = logs[i].substr(spacePos + 1);

        if (status == "FAILED") {
            bool found = false;
            for (int j = 0; j < ips.size(); j++) {
                if (ips[j] == ip) {
                    counts[j]++;
                    found = true;
                    break;
                }
            }
            if (!found) {
                ips.push_back(ip);
                counts.push_back(1);
            }
        }
    }

    cout << "Suspicious IPs (3 or more failed attempts):\n";
    for (int i = 0; i < ips.size(); i++) {
        if (counts[i] >= 3) {
            cout << ips[i] << " -> " << counts[i] << " failed attempts\n";
        }
    }

    return 0;
}