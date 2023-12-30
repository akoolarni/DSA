import matplotlib.pyplot as plt

# Function to read data from a file
def read_data(AVL):
    data = []
    with open(AVL, 'r') as file:
        for line in file:
            data.append(int(line.strip().split()[-1]))
    return data

# Read data from the output files
bst_heights = read_data('output2.txt')  # BST Heights
bst_comparisons = read_data('output2.txt')  # BST Comparisons
bst_pointer_ops = read_data('output2.txt')  # BST Pointer Operations

avl_heights = read_data('output1.txt')  # AVL Heights
avl_comparisons = read_data('output1.txt')  # AVL Comparisons
avl_pointer_ops = read_data('output1.txt')  # AVL Pointer Operations

# Create x values (tree indices)
trees = list(range(1, 101))

# Plot the data
plt.figure(figsize=(12, 6))

plt.subplot(131)
plt.plot(trees, bst_heights, label='BST Heights', marker='o')
plt.plot(trees, avl_heights, label='AVL Heights', marker='x')
plt.xlabel('Tree Index')
plt.ylabel('Height')
plt.title('Tree Heights Comparison')
plt.legend()

plt.subplot(132)
plt.plot(trees, bst_comparisons, label='BST Comparisons', marker='o')
plt.plot(trees, avl_comparisons, label='AVL Comparisons', marker='x')
plt.xlabel('Tree Index')
plt.ylabel('Comparisons')
plt.title('Comparisons Comparison')
plt.legend()

plt.subplot(133)
plt.plot(trees, bst_pointer_ops, label='BST Pointer Operations', marker='o')
plt.plot(trees, avl_pointer_ops, label='AVL Pointer Operations', marker='x')
plt.xlabel('Tree Index')
plt.ylabel('Pointer Operations')
plt.title('Pointer Operations Comparison')
plt.legend()

plt.tight_layout()
plt.show()

