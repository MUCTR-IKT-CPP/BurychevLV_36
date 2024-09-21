#include <iostream>
#include <cstdlib>
#include <ctime> 
using namespace std;

const int diap1 = 0;
const int diap2 = 20;

/*
 * Cортировка массива вставками
 *
 * @param arr массив.
 * @param len длина массива.
 * @return отсортированный массив.
 */

void insertionSort(float *arr, int len) {
    for(int i=1;i<len;i++)     
	for(int j=i;j>0 && arr[j-1]>arr[j];j--) 
			swap(arr[j-1],arr[j]);    
    }

/*
 * Функция поиск последовательнсотей
 *
 * @param arr массив.
 * @param len длина массива.
 * @param z - параметр выбора в switch - case
 * @return возрастающая, убывающая, чередующаяся последовательность.
 */

void bubbleSort(int *arr[], int size) {
    for (int i = 0; i < size - 1; ++i) {
        for (int j = 0; j < size - i - 1; ++j) {
            if (arr[j] > arr[j + 1]) {
                // Обмен значениями
                std::swap(arr[j], arr[j + 1]);
            }
        }
    }
}

void Posled(float *arr, int len, int z) {
    int count = 1;  
    switch (z)
    {
    case 1: 
    {
        printf("vozr posled:\n");
        for (int i = 1; i < len; i++) {
            if (arr[i] > arr[i - 1]) {
                count++;
            } else {
                if (count >= 3) {
                    printf("posledovatelnost: ");
                    for (int j = i - count; j < i; j++) {
                        printf("%.2f ", arr[j]);
                    }
                    printf("\n");
                }
                count = 1;
            }
        }
        if (count >= 3) {
            printf("posledovatelnost: ");
            for (int j = len - count; j < len; j++) {
                printf("%.2f ", arr[j]);
            }
            printf("\n");
        }
        break;
     } 
     case 2: 
     { 
        printf("ubiv posled:\n");
        for (int i = 1; i < len; i++) {
            if (arr[i] < arr[i - 1]) {
                count++;
            } else {
                if (count >= 3) {
                    printf("posledovatelnost: ");
                    for (int j = i - count; j < i; j++) {
                        printf("%.2f ", arr[j]);
                    }
                    printf("\n");
                }
                count = 1;
            }
        }
        if (count >= 3) {
            printf("posledovatelnost: ");
            for (int j = len - count; j < len; j++) {
                printf("%.2f ", arr[j]);
            }
            printf("\n");
        }
        break;
     }

     case 3:
     {
        printf("chered posled:\n");
        int direction = 0;

        for (int i = 1; i < len; i++) {
            if ((direction == 0 && arr[i] != arr[i - 1]) || 
                (direction == 1 && arr[i] < arr[i - 1]) || 
                (direction == -1 && arr[i] > arr[i - 1])) {
                count++;
                direction = (arr[i] > arr[i - 1]) ? 1 : -1; 
            } else {
                if (count >= 3) {
                    printf("posledovatelnost: ");
                    for (int j = i - count; j < i; j++) {
                        printf("%.2f ", arr[j]);
                    }
                    printf("\n");
                }
                count = 1;
                direction = 0;
            }
        }
        if (count >= 3) {
            printf("posledovatelnost: ");
            for (int j = len - count; j < len; j++) {
                printf("%.2f ", arr[j]);
            }
            printf("\n");
        }
        break;
     }
    
    default:
        printf("net takogo varianta!\n");
        break;
    }
}

/*
 * Генерация рандомного числа
 *
 * @param diap1 - начало диапазона случайного числа.
 * @param diap2 - конец диапазона случайного числа.
 * @return рандомное число.
 */


int generateRandomChisl(int diap1, int diap2)
{ 
    int rand_chisl = rand() % (diap2 - diap1 + 1) + diap1;
    return rand_chisl;
}

/*
 * функция - реализация выбора пользователя Case1
 *
 * @param array - массив.
 * @param len - длина массива.
 * @return массив рез, где элементы - максимальное и минимальное значения в массиве, 
 * их индексы, среднее арифметическое
 * и медианное значений среди всех элементов массива
 */

float* Case1(float *array, int len) 
{
    float min = 1000000000;
    float max = array[0];
    int ind_min = 0;
    int ind_max = 0;
    float mediana = 0;

    float *res = new float[6]; 

    for (int i = 0; i < len; i++) 
    {
        if (array[i] < min)
        {
            min = array[i];
            ind_min = i;
        }
    
        if (array[i] > max)
        {
            max = array[i];
            ind_max = i;
        } 
    }

    float sr_ar = (min + max) / 2;
    //mediana = qsort(array[len / 2]); 
    res[0] = min;
    res[1] = ind_min;
    res[2] = max;
    res[3] = ind_max;
    res[4] = sr_ar;

    for (int i = 0; i < len - 1; ++i) {
        for (int j = 0; j < len - i - 1; ++j) {
            if (array[j] > array[j + 1]) {
                std::swap(array[j], array[j + 1]);
            }
        }
    }
    // insertionSort(array)
    // array = 
    //qsort(array); 

    // for (int i = 0; i < len; i++)
    // {
    //     if (sr_ar - 
    // }




    mediana = array[len / 2];
    res[5] = mediana;

    return res;
}

/*
 * функция - манипуляция с массивом
 *
 * @param array - массив.
 * @param N - длина массива.
 * @param x - параметр выбора switch - case.
 * @return case1 (выборка из массива - алгоритм описан выше) / case2 (сортировка вставками одномерного массива)
 * /case3 (вывод среза массива)/case4 (вывод поседовательности - алгоритм описан выше) .
 * 
 */

void ManipulWithArray(float Array[], int N, int x)
{
    switch(x)
    {
        case 1: 
        {
            float* result = Case1(Array, N); 
            cout << "min: " << result[0] << ", index minimalnogo: " << result[1] << endl;
            cout << "max: " << result[2] << ", index maximalnogo: " << result[3] << endl;
            cout << "srednee: " << result[4] << ", mediana: " << result[5] << endl;
            delete[] result; 
            break;
        }
        case 2: 
            {
            float result[N];

            for (int j = 0; j < N; j++)
            {
                result[j] = Array[j];
            } 

            insertionSort(result, N);
            for (int i = 0; i < N; i++)
            {
                cout << result[i] << endl; 
            }
            delete[] Array; 
            break;
        }

        case 3:
        {
            int a;
            int b;
            float result[N];

            for (int j = 0; j < N; j++)
            {
                result[j] = Array[j];
            }     

            std::cout << "Vvedi s kakogo indexa srez: ";
            std::cin >> a;
            if (a <= 0) 
            {
                a = 1;
             cout << "schitaem s pervogo chisla" << endl;   
            }
            std::cout << "Vvedi do kakogo indexa srez: ";
            std::cin >> b;

            if (b >= N) 
            {
                b = N;
             cout << "schitaem do konca massiva" << endl;   
            }

            for (int j = a - 1; j < b; j++)
            {
                cout << result[j] << endl;

            }    
            break;
            delete[] Array; 

        }

        case 4:
        {
          int W;
          std::cout << "Vvedi variant: ";
          std::cin >> W;
          return Posled(Array, N, W);

        }

        default: 
            std::cout << "net takogo varianta";
            break;
    }
}

int main()
{
    srand(time(0));

    int Q;
    int N;
    float *arr;

    std::cout << "Vvod N: ";
    std::cin >> N;

    arr = new float[N];

    for (int i = 0; i < N; i++) 
    {
        arr[i] = generateRandomChisl(diap1, diap2);
        cout << arr[i] << " ";
    }
    cout << endl;

    std::cout << "Chto hotite sdelat: ";
    std::cin >> Q;

    ManipulWithArray(arr, N, Q);
    delete[] arr;

    return 0;
}
