import matplotlib.pyplot as plt

# Read data from output file
def read_frequency_data(file_path):
    ranks = []
    frequencies = []
    with open(file_path, 'r') as file:
        for line in file:
            rank, freq, _ = line.split()
            ranks.append(int(rank))
            frequencies.append(int(freq))
    return ranks, frequencies

first_ranks, first_frequencies = read_frequency_data("frequency.txt")
second_ranks, second_frequencies = read_frequency_data("frequency_old_text.txt")

# Plot both datasets in log-log scale
plt.figure(figsize=(10, 6))
plt.loglog(first_ranks, first_frequencies, marker='o', linestyle='-', label="Moby Dick")
plt.loglog(second_ranks, second_frequencies, marker='x', linestyle='-', label="El principito")

plt.xlabel("Rank")
plt.ylabel("Frequency")
plt.title("Zipf's Law - Word Frequency Comparison")
plt.legend()
plt.show()
