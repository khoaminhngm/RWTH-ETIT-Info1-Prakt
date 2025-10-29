//////////////////////////////////////////////////////////////////////////////
// Praktikum Informatik 1 MMXXV
// Versuch 02
//
// Datei:  main.cpp
// Inhalt: Hauptprogramm
//////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <chrono>

//Iterativ
long fibonacci(int n)
{
    long previousFib = 1;
    long currentFib = 1;
    if(n == 0)
    {
        return 0;
    }
    if(n == 1)
    {
        return 1;
    }
    for (int i = 0; i <= n; i++)
    {
        long newFib = previousFib + currentFib ;
        previousFib = currentFib ;
        currentFib = newFib ;
    }
    return currentFib ;
}

int main ()
{
	// Start - Timer für Geschwindigkeitsmessung:
	auto start = std::chrono::high_resolution_clock::now();

	// Main
    std::cout << " Fibonacci - Zahlen von 0 bis 12:" << std::endl ;
    for (int i = 1; i <= 50 ; i ++)
    {
        std::cout << "f(" << i << ") = " << fibonacci(i) << std::endl ;
    }

    // End Tiauto end = std::chrono::high_resolution_clock::now();
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> duration = end - start;
    std::cout << duration.count() << " ms" << std::endl;

    return 0;
}
