
### 1, con trỏ và mảng một chiều

```
int arr[] = { 32, 13, 66, 11, 22 };
```

- địa chỉ của mảng một chiều cũng là địa chỉ của phần tử đầu tiên (&arr[0]).
- việc sử dụng tên mảng một chiều cũng chính là chúng ta đang sử dụng địa chỉ của mảng một chiều (&arr tương đương với arr).
- arr, arr + 1, arr + 2, arr + 3, arr + 4 chính là địa chỉ của 5 phần tử của mảng arr. vì vậy chúng ta có thể sử dụng toán tử * để truy xuất giá trị của chúng

Tổng kết:</br>

- Tên mảng là một hằng địa chỉ (hằng con trỏ), nó chính là địa chỉ của phần tử đầu tiên của mảng.
- Địa chỉ:
  + arr　<=>　&arr[0]　<=>　&arr
  + (arr + i)　<=>　&arr[i]
- Giá trị:

  + *arr　<=>　arr[0]
  + *(arr + i)　<=>　arr[i]

### 2, con trỏ và mảng ký tự
