import array

def partition(arr, low, high):
  p_index = high
  pivot = arr[p_index]
  i = low
  for j in range(low, high + 1):
    if arr[j] < pivot:
      arr[j], arr[i] = arr[i], arr[j]
      i += 1
  arr[i], arr[p_index] = arr[p_index], arr[i]
  return i

def qsort(arr, low, high):
  if low < high:
    p = partition(arr, low, high)
    qsort(arr, low, p - 1)
    qsort(arr, p + 1, high)

def main():
  ar = array.array('b',[5, 4, 7, 1, 9])
  qsort(ar, 0, len(ar) - 1)
  print(ar)

if __name__ == "__main__":
    main()