//problem 11//
#include <iostream>
#include <fstream>

int main()
{
    std::ifstream file("grid.txt");
    int arr[20][20];
    for(int i = 0; i<20;i++) 
        for(int j = 0; j<20;j++) 
            file >> arr[i][j]; ///fills array
    long maxln(-1), current;
    for(int i = 0; i < 20; i++) {
        for(int j = 0; j < 20; j++) {
            //find current line
            if(i + 3 < 20)
            {
                current = arr[i][j] * arr[i + 1][j] * arr[i + 2][j] * arr[i +3][j];
                if(maxln < current)
                    maxln = current;
            }
            //find current column
            if(j + 3 < 20)
            {
                current = arr[i][j] * arr[i][j+1] * arr[i][j+2] * arr[i][j+3];
                if(maxln < current)
                    maxln = current;
            }
            //find current right facing diagn
            if(i + 3 < 20 && j + 3 < 20)
            {
                current = arr[i][j] * arr[i+1][j+1] * arr[i+2][j+2] * arr[i+3][j+3];
                if(maxln < current)
                    maxln = current;
            }
            //find current left facing diagn
            if(i + 3 < 20 && j >= 3)//to not go left of the array 
            {
                current = arr[i][j] * arr[i+1][j-1] * arr[i+2][j-2] * arr[i+3][j-3];
                if(maxln < current)
                    maxln = current;
            }
        }
    }
    std::cout << maxln << std::endl;
}