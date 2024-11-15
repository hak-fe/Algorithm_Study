#include <bits/stdc++.h>

constexpr int size = 300 * 3;
int N, M;
std::string str[size];
const int dx[] = {1, -1, 0, 0};
const int dy[] = {0, 0, -1, 1};

int main(int argc, char* argv[])
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr), std::cout.tie(nullptr);

    std::cin >> N >> M;

    for(int i = 0; i < N * 3; i++)
        std::cin >> str[i];

    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < M; j++)
        {
            for(int k = 0; k < 4; k++)
            {
                int nX = i*3 + 1 + dx[k];
                int nY = j*3 + 1 + dy[k];

                if(str[nX][nY] == '.')
                    continue;
                
                int nX2 = nX + dx[k];
                int nY2 = nY + dy[k];

                if(nX2 >= 0 && nX2 < N * 3 && nY2 >= 0 && nY2 < M * 3)
                    str[nX2][nY2] = '#';
            }
            str[i * 3 + 1][j * 3 + 1] = '#';
        }
    }
    for(int i = 0; i < N * 3; i++)
        std::cout << str[i] << '\n';
    return 0;
}