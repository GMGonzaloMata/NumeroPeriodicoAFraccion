#include <iostream>
#include <string>
#include <cmath>

int gcd(int a, int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

int main() {
    std::string decimalStr;
    std::cout << "Ingresa un número decimal periódico de la siguiente manera(por ejemplo, 0.333... = 0.3(3)): ";
    std::cin >> decimalStr;

    size_t posDecimal = decimalStr.find(".");
    std::string parteEntera = decimalStr.substr(0, posDecimal);
    std::string parteDecimal = decimalStr.substr(posDecimal + 1);

    int entero = std::stoi(parteEntera);

    int numerador = 0;
    int denominador = 1;

    if (parteDecimal.find("(") == std::string::npos) {
        int longitudDecimal = parteDecimal.size();
        numerador = std::stoi(parteDecimal);
        denominador = std::pow(10, longitudDecimal);
    } else {
        size_t posPeriodico = parteDecimal.find("(");
        std::string noPeriodico = parteDecimal.substr(0, posPeriodico);
        std::string periodo = parteDecimal.substr(posPeriodico + 1, parteDecimal.size() - posPeriodico - 2);

        int longitudNoPeriodico = noPeriodico.size();
        int longitudPeriodo = periodo.size();
        int numeradorNoPeriodico = std::stoi(noPeriodico);
        int numeradorPeriodo = std::stoi(periodo);
        
        numerador = (std::pow(10, longitudNoPeriodico + longitudPeriodo) - std::pow(10, longitudNoPeriodico)) * entero +
                    (std::pow(10, longitudPeriodo) - 1) * numeradorNoPeriodico + numeradorPeriodo;
        denominador = (std::pow(10, longitudNoPeriodico + longitudPeriodo) - std::pow(10, longitudNoPeriodico));
    }

    int maximoComunDivisor = gcd(numerador, denominador);
    numerador /= maximoComunDivisor;
    denominador /= maximoComunDivisor;

    std::cout << "El número " << decimalStr << " es igual a la fracción " << numerador << "/" << denominador << std::endl;

    return 0;
}

