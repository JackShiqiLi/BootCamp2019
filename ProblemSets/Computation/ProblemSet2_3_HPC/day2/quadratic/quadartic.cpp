#include <iostream>
#include <cmath>

int main()
{
  float a, b, c, x1, x2, discriminant, repart, impart;
  std::cout << "Enter coefficients";
  std::cin >> a >> b >> c;
  discriminant = b*b - 4*a*c;

  if (discriminant > 0)
  {
    x1 = (-b + sqrt(discriminant)) / (2 * a);
    x2 = (-b - sqrt(discriminant)) / (2 * a);
    std::cout << "Roots are real and different." << '\n';
    std::cout << "x1 = " << x1 << '\n';
    std::cout << "x1 = " << x2 << '\n';
  }
  else if (discriminant == 0) {
    std::cout << "Roots are real and same." << '\n';
    x1 = (-b + sqrt(discriminant)) / (2 * a);
    std::cout << "x1 = x2 = " << x1 << '\n';
  }
  else {
    repart = -b / (2 * a);
    impart = sqrt(-discriminant)/(2*a);
    std::cout << "Roots are complex and differert." << '\n';
    std::cout << "x1 = " << repart << "+" << impart << "i" << '\n';
    std::cout << "x2 = " << repart << "-" << impart << "i" << '\n';
  }
  return 0;
}
