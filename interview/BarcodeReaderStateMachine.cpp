/* This is just an example for practice. It was not asked in any interview. */

#include <iostream>
#include <string>

enum class BarcodeState {
    START,
    READING,
    END
};

class BarcodeReader {
private:
    BarcodeState currentState;
    std::string barcodeData;

public:
    BarcodeReader() : currentState(BarcodeState::START) {}

    void processInput(char input) {
        switch (currentState) {
            case BarcodeState::START:
                if (input == '*') {
                    currentState = BarcodeState::READING;
                    barcodeData.clear();
                }
                break;
            case BarcodeState::READING:
                if (input == '#') {
                    currentState = BarcodeState::END;
                    processBarcode();
                } else {
                    barcodeData += input;
                }
                break;
            case BarcodeState::END:
                if (input == '*') {
                    currentState = BarcodeState::READING;
                    barcodeData.clear();
                }
                break;
        }
    }

    void processBarcode() {
        std::cout << "Barcode: " << barcodeData << std::endl;
    }
};

int main() {
    BarcodeReader reader;
    std::string input = "*123456789#*987654321#";

    for (char c : input) {
        reader.processInput(c);
    }

    return 0;
}
