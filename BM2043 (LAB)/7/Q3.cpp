#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>

using namespace std;

void flood_Fill(vector<vector<int>>& image, int sr, int sc, int new_Colour){
    int m = image.size();
    if (m == 0) return;
    int n = image[0].size();
    
    int original_Colour = image[sr][sc];
    if (original_Colour == new_Colour) return;

    vector<vector<bool>> visited_Pixel(m, vector<bool>(n, false));

    //dfs implementation
    vector<pair<int, int>> stack;
    stack.push_back({sr, sc});
    visited_Pixel[sr][sc] = true;

    while(!stack.empty()){
        int i = stack.back().first;
        int j = stack.back().second;
        stack.pop_back();

        image[i][j] = new_Colour;

        //checking neighbours 
        vector<pair<int, int>> neighbors = {{i - 1, j}, {i + 1, j}, {i, j - 1}, {i, j + 1}};
        for(const auto &neigh : neighbors){
            int x = neigh.first;
            int y = neigh.second;
            if(x >= 0 && x < m && y >= 0 && y < n && !visited_Pixel[x][y] && image[x][y] == original_Colour){
                stack.push_back({x, y});
                visited_Pixel[x][y] = true;
            }
        }
    }
}

void print_Image(const vector<vector<int>>& image){
    for (const auto &row : image) {
        for (int pixel : row) {
            cout << pixel << " ";
        }
        cout << endl;
    }
}

int main(){
    //input matrix
    vector<vector<int>> image = {
        {1, 1, 1},
        {1, 1, 0},
        {1, 0, 1}
    };

    int sr = 1, sc = 1, new_Colour = 2;

    cout << "Original Image is: " << endl;
    print_Image(image);

    flood_Fill(image, sr, sc, new_Colour);

    cout << "Image after flood fill is: " << endl;
    print_Image(image);

    return 0;
}

//TIME complexity - O(m x n)
//SPACE complexity - O(m x n)
//reason for multiplied space and time complexities as a product of m & n is due to the use of adjacency matrix which increases both drastically
