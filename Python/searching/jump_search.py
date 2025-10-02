import math

def jump_search(arr, target):
    """
    Perform jump search to find the target value in the given sorted list.

    Parameters:
        arr (list): The sorted list to be searched.
        target: The value to be searched for.

    Returns:
        int: The index of the target value if found, otherwise -1.
    """
    n = len(arr)
    step = int(math.sqrt(n))
    prev = 0
    while arr[min(step, n) - 1] < target:
        prev = step
        step += int(math.sqrt(n))
        if prev >= n:
            return -1
    while arr[prev] < target:
        prev += 1
        if prev == min(step, n):
            return -1
    if arr[prev] == target:
        return prev
    return -1

# Example usage:
arr = [2, 3, 4, 10, 40]
target = 10
result = jump_search(sorted(arr), target)
if result != -1:
    print(f"Jump Search: Element found at index {result}")
else:
    print("Jump Search: Element not found")
