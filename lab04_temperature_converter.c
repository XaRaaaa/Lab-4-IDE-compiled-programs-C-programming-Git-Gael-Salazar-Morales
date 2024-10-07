    #include <stdio.h>

    float celsius_to_fahrenheit(float celsius) {
        return (celsius * 9.0 / 5.0) + 32.0;
    }

    float fahrenheit_to_celsius(float fahrenheit) {
        return (fahrenheit - 32.0) * 5.0 / 9.0;
    }

    float celsius_to_kelvin(float celsius) {
        return celsius + 273.15;
    }

    float kelvin_to_celsius(float kelvin) {
        return kelvin - 273.15;
    }

    float fahrenheit_to_kelvin(float fahrenheit) {
        return celsius_to_kelvin(fahrenheit_to_celsius(fahrenheit));
    }

    float kelvin_to_fahrenheit(float kelvin) {
        return celsius_to_fahrenheit(kelvin_to_celsius(kelvin));
    }

    void categorize_temperature(float celsius) {
        if (celsius < 0) {
            printf("Category: Freezing\nAdvisory: Wear a heavy jacket.\n");
        } else if (celsius < 10) {
            printf("Category: Cold\nAdvisory: Wear a jacket.\n");
        } else if (celsius < 25) {
            printf("Category: Comfortable\nAdvisory: Enjoy the weather.\n");
        } else if (celsius < 35) {
            printf("Category: Hot\nAdvisory: Stay hydrated.\n");
        } else {
            printf("Category: Extreme Heat\nAdvisory: Stay indoors and stay cool.\n");
        }
    }

    int main() {
        float temp;
        float converted_temp;
        int input_scale;
        int target_scale;

        printf("Enter the temperature value: ");
        if (scanf("%f", &temp) != 1) {
            printf("Invalid input. Please enter a valid number.\n");
            return 1;
        }

        printf("Choose the temperature scale of the input value (1: Fahrenheit, 2: Celsius, 3: Kelvin): ");
        if (scanf("%d", &input_scale) != 1 || input_scale < 1 || input_scale > 3) {
            printf("Invalid choice. Please enter 1, 2, or 3.\n");
            return 1;
        }

        printf("Choose the conversion target (1: Fahrenheit, 2: Celsius, 3: Kelvin): ");
        if (scanf("%d", &target_scale) != 1 || target_scale < 1 || target_scale > 3) {
            printf("Invalid choice. Please enter 1, 2, or 3.\n");
            return 1;
        }

        if (input_scale == target_scale) {
            printf("Invalid conversion choice. Input scale and target scale cannot be the same.\n");
            return 1;
        }

        if (input_scale == 1) { // Fahrenheit
            if (target_scale == 2) { // To Celsius
                converted_temp = fahrenheit_to_celsius(temp);
            } else {
                converted_temp = fahrenheit_to_kelvin(temp);
            }
        } else if (input_scale == 2) { // Celsius
            if (target_scale == 1) { // To Fahrenheit
                converted_temp = celsius_to_fahrenheit(temp);
            } else {
                converted_temp = celsius_to_kelvin(temp);
            }
        } else if (input_scale == 3) { // Kelvin
            if (temp < 0) { // Kelvin cannot be negative
                printf("Invalid temperature value. Kelvin cannot be negative.\n");
                return 1;
            }
            if (target_scale == 1) { // To Fahrenheit
                converted_temp = kelvin_to_fahrenheit(temp);
            } else {
                converted_temp = kelvin_to_celsius(temp);
            }
        }

        printf("Converted temperature: %f\n", converted_temp);

        if (target_scale == 1) { // Fahrenheit
            categorize_temperature(fahrenheit_to_celsius(converted_temp));
        } else if (target_scale == 2) { // Celsius
            categorize_temperature(converted_temp);
        } else { // Kelvin
            categorize_temperature(kelvin_to_celsius(converted_temp));
        }

        return 0;
    }
