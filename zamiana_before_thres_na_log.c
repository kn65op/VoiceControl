/*
 * =====================================================================================
 *
 *       Filename:  zamiana_before_thres_na_log.c
 *
 *    Description:  zamiana
 *
 *        Version:  1.0
 *        Created:  20.05.2012 21:28:21
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Tomasz Drzewiecki (tomko), kn65op@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */

#include <vector>
#include <fstream>
#include <cmath>
#include <string>

int main()
{
    std::ifstream lista("lista_bt.txt", std::ios::in);
    std::ifstream plik_in;
    std::ofstream plik_out;
    std::string nazwa;
    std::vector<double> liczby(513);
    double maks;
    while (!lista.eof())
    {
        lista >> nazwa;
        plik_in.open(nazwa, std::ios::in);
        plik_out.open(nazwa + "2", std::ios::out);
        while (!plik_in.eof())
        {
            maks = 0;
            for (auto & l : liczby)
            {
                plik_in >> l;
                if (l > maks)
                {
                    maks = l;
                }
            }
            for (auto l: liczby)
            {
                if (l)
                {
                     plik_out << (log10(l / maks) > -1) << " ";
                }
                else
                {
                    plik_out << 0 << " ";
                }
            } 
            plik_out << "\n";
        }
        plik_in.close();
        plik_out.close();
    }
    lista.close();
    return 0;
}

