#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//Writen By Mert Metin Erdemli
void bubbleSort(int arr[], int n, int *comparisonCount) { // bubble sort methodu
    int i, j;
    for (i = 0; i < n-1; i++) {
        for (j = 0; j < n-i-1; j++) {
            (*comparisonCount)++;
            if (arr[j] > arr[j+1]) {
                int temp = arr[j];          //swap ettiğimiz kısım
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

void quickSort(int arr[], int low, int high, int *comparisonCount) {  // Quick ssort methodu
    if (low < high) {
        int pivot = arr[high];
        int i = low - 1;
        int j;
        for (j = low; j <= high - 1; j++) {
            (*comparisonCount)++;
            if (arr[j] < pivot) {
                i++;
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
        int temp = arr[i + 1];    //swap ettiğimiz kısım
        arr[i + 1] = arr[high];
        arr[high] = temp;

        int partitionIndex = i + 1;

        quickSort(arr, low, partitionIndex - 1, comparisonCount);  //methodu rekürsif ettiğimiz kısım
        quickSort(arr, partitionIndex + 1, high, comparisonCount);
    }
}

int main() {
    srand(time(0));

    int sizes[] = {1000, 2000, 3000}; //arrayleri oluşturduğumuz kısım
    int numSizes = sizeof(sizes) / sizeof(sizes[0]);

    FILE *outputFile = fopen("output.txt", "a");       //outpu dosyasını oluşturduğumuz kısım

    fprintf(outputFile, "Dizi Boyutu\tBubble Sort Suresi (ms)\tQuick Sort Suresi (ms)\t\tBubble Sort K S\t\tQuick Sort K S\n");

    for (int i = 0; i < numSizes; i++) {   //arrayleri rasgele sayılar ile doldurduğumuz kısım
        int size = sizes[i];

        int *arr1 = (int*)malloc(size * sizeof(int));  //bellekten yer ayırıyoruz
        int *arr2 = (int*)malloc(size * sizeof(int));
        for (int j = 0; j < size; j++) {
            int num = rand() % 10000;
            arr1[j] = num;
            arr2[j] = num;
        }

        int bubbleComparisonCount = 0;   //BS için karşılaştırmaların sayılarını tuttuğumuz değişken
        clock_t bubbleStart = clock();     //süre tuttuğumzu kısım
        bubbleSort(arr1, size, &bubbleComparisonCount);
        clock_t bubbleEnd = clock();
        double bubbleTime = ((double)(bubbleEnd - bubbleStart) * 1000) / CLOCKS_PER_SEC;  //geçen zamanı hesapladığımız kısım

        int quickComparisonCount = 0;   //QS için karşılaştırmaların sayılarını tuttuğumuz değişken
        clock_t quickStart = clock();   //süre tuttuğumzu kısım
        quickSort(arr2, 0, size - 1, &quickComparisonCount);
        clock_t quickEnd = clock();
        double quickTime = ((double)(quickEnd - quickStart) * 1000) / CLOCKS_PER_SEC;   //geçen zamanı hesapladığımız kısım

        //hesaplanan değerleri dosyaya yazdırdığımız kısım
        fprintf(outputFile, "%d\t\t%.2f\t\t\t%.2f\t\t\t\t%d\t\t\t%d\n", size, bubbleTime, quickTime, bubbleComparisonCount, quickComparisonCount);

        free(arr1);             //oluşturudğumuz bellek alaklarını serbest bıraktığımız kısım
        free(arr2);
    }

    fclose(outputFile);        //dosyayı kapattığımız kısım

    return 0;
}
































































//Writen By Mert Metin Erdemli