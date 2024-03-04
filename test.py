import numpy as np

# Tạo một mảng NumPy ví dụ
arr = np.array([1, 2, 3, 4, 5, 6, 7, 8, 9])

# Chia mảng thành các phần tỉ lệ theo số lượng phần
ratios = [0.4, 0.3, 0.3]
result = np.array_split(arr, (np.cumsum(np.round(np.array(ratios) * len(arr))).astype(int)))

print(result)
print(np.array(ratios) * len(arr))
