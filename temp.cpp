#include <iostream>
using namespace std;

double celsiusToFahrenheit(double celsius) {
    return celsius * 9/5 + 32;
}

double celsiusToKelvin(double celsius) {
    return celsius + 273.15;
}

double fahrenheitToCelsius(double fahrenheit) {
    return (fahrenheit - 32) * 5/9;
}

double fahrenheitToKelvin(double fahrenheit) {
    return (fahrenheit - 32) * 5/9 + 273.15;
}

double kelvinToCelsius(double kelvin) {
    return kelvin - 273.15;
}

double kelvinToFahrenheit(double kelvin) {
    return kelvin * 9/5 - 459.67;
}

void convertTemperature(double value, char unit) {
    double resultCelsius, resultFahrenheit, resultKelvin;

    switch (unit) {
        case 'C':
        case 'c':
            resultCelsius = value;
            resultFahrenheit = celsiusToFahrenheit(value);
            resultKelvin = celsiusToKelvin(value);
            break;

        case 'F':
        case 'f':
            resultFahrenheit = value;
            resultCelsius = fahrenheitToCelsius(value);
            resultKelvin = fahrenheitToKelvin(value);
            break;

        case 'K':
        case 'k':
            resultKelvin = value;
            resultCelsius = kelvinToCelsius(value);
            resultFahrenheit = kelvinToFahrenheit(value);
            break;

        default:
            cout << "Invalid unit. Please enter 'C', 'F', or 'K'." << endl;
            return;
    }

    cout << value << " " << unit << " is equal to:" << endl;
    cout << resultCelsius << " C" << endl;
    cout << resultFahrenheit << " F" << endl;
    cout << resultKelvin << " K" << endl;
}

int main() {
    double temperatureValue;
    char temperatureUnit;

    cout << "Enter temperature value: ";
    cin >> temperatureValue;

    cout << "Enter temperature unit (C, F, or K): ";
    cin >> temperatureUnit;

    convertTemperature(temperatureValue, temperatureUnit);

    return 0;
}
