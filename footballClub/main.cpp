#include <iostream>
#include <vector>

using namespace std;

template <typename T = char> size_t CreateArrayAtMemory(void*, size_t bs)
{
    return bs * sizeof(T);
}

template <typename T = char, typename ... Args>
size_t CreateArrayAtMemory(void* p, size_t bs, Args ... args)
{
    size_t R = 0;
    size_t PS = sizeof(void*);
    char* P = (char*)p;
    char* P0 = (char*)p;

    size_t BytesForAllPointers = bs * PS;
    R = BytesForAllPointers;

    char* pos = P0 + BytesForAllPointers;
    for (size_t i = 0; i < bs; i++)
    {
        char** pp = (char**)P;
        if (p)
            *pp = pos;
        size_t RLD = CreateArrayAtMemory<T>(p ? pos : nullptr, args ...);
        P += PS;
        R += RLD;
        pos += RLD;
    }
    return R;
}

class FootballClub {
private:
    int***** f5;
public: 
    FootballClub(int***** f)
        : f5(f)
    {

    }

    void setPlayer(int footballTeam, int footballPlayer, int numOfPlayer) {
        f5[footballTeam][0][0][0][footballPlayer] = numOfPlayer;
    }

    void setTrainer(int footballTeam, int footballPlayer, int numOfTrainer, int footballTrainer) {
        f5[footballTeam][0][0][footballTrainer][footballPlayer] = numOfTrainer;
    }
    

    void print() {
        std::cout << "team#1:\n";
        for (size_t i = 0; i < 11; i++)
        {
            std::cout << (int)f5[0][0][0][0][i] << " ";
        }
        std::cout << "trainer#1: ";
        std::cout << (int)f5[0][0][0][1][0];
        std::cout << "\nteam#2:\n";
        for (size_t i = 0; i < 11; i++)
        {
            std::cout << (int)f5[1][0][0][0][i] << " ";
        }
        std::cout << "trainer#2: ";
        std::cout << (int)f5[1][0][0][2][0];
    }
};



int main() {
    int j = 0x21;
    size_t n5 = CreateArrayAtMemory<int>(nullptr, 2, 3, 4, 5, 6);
    vector<char> a5(n5);
    int***** f5 = (int*****)a5.data();
    CreateArrayAtMemory<int>(f5, 2, 3, 4, 5, 6);

    FootballClub club(f5);
    for (size_t i = 0; i < 11; i++)
    {
        club.setPlayer(0, i, i + 1);
        club.setTrainer(0, i, 1, 0);
        club.setPlayer(1, i, i + 6);
        club.setTrainer(0, i, 1, 1);
        club.setTrainer(1, i, 2, 1);
    }

    club.print();

    return 0;
}