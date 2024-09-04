#include <iostream>
#include <cstdlib>
#include <ctime> 
using namespace std;

//функция generateRandomString - функция генерации рандомной строки из букв английского алфавита, где праметр - длина строки.
//Внутри инициализация генератор случайных чисел с текущим временем, изначальная строки без букв и дальше по циклу генерируется случайная буква и прибавляется к строке

string generateRandomString(int length) 
{
    srand(time(0)); 

    string strok = ""; 
    for (int i = 0; i < length; i++) 
    {
        strok += ('a' + rand() % ('z' - 'a'));
    }

    return strok;
}

//Главная функция main, в которой инициализируются count_iter для подсчета общего 
//колличества итераций подбора всех букв в строке;
//max_count_iter_for_simv для максимального колличетсва итераций полдбора одной буквы;
//length, обозначающий длину строки, которую необходимо сгенерировать;
//simv, обозначающий букву, которая подбиралась дольше всего;
//rand_strok - генерация строки функцией generateRandomStringж
//Далее по коду в цикле мы проходим по строке, где перед основной логикой обьявляем переменные bukv 
//и iter_simv для получения информации о последней подобранной букве и колличетсве итераций,
//с которой эта буква была подобрана
//далее мы запускаем цикл while, в котором пока не сгенерируется нужна по счету буква, общий счетчик итераций
//и счетчик итераций по конркетной букве будет увлечиваться
//следом в цикле if мы сравниваем количество итераций по символу с максимальным колличеством итераций, и если
//он больше, в переменную max_count_iter_for_simv мы записываем iter_simv, а наша искомая буква становиться последней
//на данный момент подобранной в rand_strok.
//потом мы обнуляем iter_simv для нвого прохода по буквам.
//в конце после цикла мы выводим искомые значения.

int main()
{
    int count_iter = 0;
    int max_count_iter_for_simv = 0;
    int length = 1000;
    string simv = "";
    string rand_strok = generateRandomString(length);

    for (int i = 0; i < length; i++)
    {
        char bukv;
        int iter_simv = 0;

        while (bukv != rand_strok[i])
        {
        bukv = ('a' + rand() % ('z' - 'a'));
        count_iter += 1;
        iter_simv += 1;
        }
        if (iter_simv > max_count_iter_for_simv)
        {
            max_count_iter_for_simv = iter_simv;
            simv = rand_strok[i];
        }

        iter_simv = 0;
    }

    cout << rand_strok << endl;
    cout << count_iter << endl;
    cout << simv << endl;
    cout << max_count_iter_for_simv << endl;
    
    return 0;
}