#include "read_csv.h"
#include "string"

using namespace std;

int main(int argc, char const *argv[]) {
    /* code */
    string label_name = "bad";
    Reader reader = Reader(label_name);
    vector<vector<string>> strResult = reader.read_csv(
            "/Users/tian/Projects/c_plus_plus/my_projects/decision_tree/src/test.csv");

    TrainData train_data = reader.find_split_point(strResult);

    cout << "id is :" << endl;
    for (size_t i = 0; i < train_data.ids.size(); i++) {
        cout << train_data.ids[i] << endl;
    }

    cout << "label is :" << endl;
    for (size_t i = 0; i < train_data.label.size(); i++) {
        cout << train_data.label[i] << endl;
    }

    return 0;
}