#include <stdio.h>
#include <math.h>

int isPrime(int n) {
    if (n < 2) return 0;
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) return 0;
    }
    return 1;
}

int main() {
    int arr[100], currentLength = 0, choice;

    while (1) {
        printf("\nMENU\n");
        printf("1. Nhập số phần tử và giá trị các phần tử\n");
        printf("2. In ra giá trị các phần tử đang quản lý\n");
        printf("3. In ra giá trị các phần tử chẵn và tính tổng\n");
        printf("4. In ra giá trị lớn nhất và nhỏ nhất trong mảng\n");
        printf("5. In ra các phần tử là số nguyên tố và tính tổng\n");
        printf("6. Thống kê số lần xuất hiện của một số\n");
        printf("7. Thêm một phần tử vào vị trí chỉ định\n");
        printf("8. Thoát\n");
        printf("Lựa chọn của bạn: ");
        scanf("%d", &choice);

        if (choice == 8) break;

        switch (choice) {
            case 1: {
                printf("Nhập số phần tử muốn nhập (tối đa 100): ");
                scanf("%d", &currentLength);
                if (currentLength < 0 || currentLength > 100) {
                    printf("Số phần tử không hợp lệ.\n");
                    currentLength = 0;
                } else {
                    printf("Nhập các phần tử:\n");
                    for (int i = 0; i < currentLength; i++) {
                        scanf("%d", &arr[i]);
                    }
                }
                break;
            }
            case 2: {
                if (currentLength == 0) {
                    printf("Mảng trống.\n");
                } else {
                    printf("Các phần tử trong mảng: ");
                    for (int i = 0; i < currentLength; i++) {
                        printf("%d ", arr[i]);
                    }
                    printf("\n");
                }
                break;
            }
            case 3: {
                int sumEven = 0;
                printf("Các phần tử chẵn: ");
                for (int i = 0; i < currentLength; i++) {
                    if (arr[i] % 2 == 0) {
                        printf("%d ", arr[i]);
                        sumEven += arr[i];
                    }
                }
                printf("\nTổng các phần tử chẵn: %d\n", sumEven);
                break;
            }
            case 4: {
                if (currentLength == 0) {
                    printf("Mảng trống.\n");
                } else {
                    int max = arr[0], min = arr[0];
                    for (int i = 1; i < currentLength; i++) {
                        if (arr[i] > max) max = arr[i];
                        if (arr[i] < min) min = arr[i];
                    }
                    printf("Giá trị lớn nhất: %d\n", max);
                    printf("Giá trị nhỏ nhất: %d\n", min);
                }
                break;
            }
            case 5: {
                int sumPrimes = 0;
                printf("Các phần tử là số nguyên tố: ");
                for (int i = 0; i < currentLength; i++) {
                    if (isPrime(arr[i])) {
                        printf("%d ", arr[i]);
                        sumPrimes += arr[i];
                    }
                }
                printf("\nTổng các số nguyên tố: %d\n", sumPrimes);
                break;
            }
            case 6: {
                int x, count = 0;
                printf("Nhập số cần thống kê: ");
                scanf("%d", &x);
                for (int i = 0; i < currentLength; i++) {
                    if (arr[i] == x) count++;
                }
                printf("Số lần xuất hiện của %d: %d\n", x, count);
                break;
            }
            case 7: {
                if (currentLength >= 100) {
                    printf("Mảng đã đầy, không thể thêm phần tử.\n");
                } else {
                    int addValue, addIndex;
                    printf("Nhập giá trị muốn thêm: ");
                    scanf("%d", &addValue);
                    printf("Nhập vị trí muốn thêm (0-%d): ", currentLength);
                    scanf("%d", &addIndex);

                    if (addIndex < 0 || addIndex > currentLength) {
                        printf("Vị trí không hợp lệ.\n");
                    } else {
                        for (int i = currentLength; i > addIndex; i--) {
                            arr[i] = arr[i - 1];
                        }
                        arr[addIndex] = addValue;
                        currentLength++;
                    }
                }
                break;
            }
            default:
                printf("Lựa chọn không hợp lệ.\n");
        }
    }

    printf("Chương trình đã thoát.\n");
    return 0;
}
