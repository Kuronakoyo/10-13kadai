#include <stdio.h>


/*
【問題】
先ほどのnewとdeleteで配列を確保する処理を、
クラスにしてデストラクタで自動でdeleteが呼ばれるようにしてください。
*/
class Array
{
    // この中を実装
public:
    Array()
    {
        newArray = nullptr;
    };
    ~Array()
    {
        delete[] newArray;
        newArray = nullptr;
        printf("%p\n", newArray);
    }
    void Create(int x)
    {
        newArray = new int[x];
        rangenum = x;
    }
    int Get(int getx)
    {
        if (getx >= 0 && getx < rangenum)
            return newArray[getx];
        else
            return NULL;
    }

    void Set(int setx)
    {
        if (setx >= 0 && setx < rangenum)
            newArray[setx] = setx;
        else
            return;
    }

private:
    int rangenum;
    int* newArray;
    
};
int main()
{
    Array array;

    array.Create(1000);


    for (int i = 0; i < 1000; ++i)
    {
        array.Set(i);
    }

    for (int i = 0; i < 1000; ++i)
    {
        printf("num = %d\n", array.Get(i));
    }

    // 配列外参照しようとした際を確認
    printf("num = %d\n", array.Get(-1));
    printf("num = %d\n", array.Get(1000));
}
