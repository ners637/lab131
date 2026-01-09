import matplotlib.pyplot as plt

# Размеры тестовых файлов (соответствует числам элементов)
x_values = [10, 100, 1000, 10000, 100000]

# Читаем время из time.txt
heap_times = []
bubble_times = []

with open("time.txt", "r") as f:
    lines = f.readlines()
    for line in lines:
        values = line.strip().split()
        if len(values) == 2:
            heap_times.append(float(values[0].replace(',', '.')))
            bubble_times.append(float(values[1].replace(',', '.')))

# Проверка
if len(heap_times) != len(x_values) or len(bubble_times) != len(x_values):
    print("Количество значений в time.txt не совпадает с ожидаемыми размерами данных!")
    exit(1)

# --- Построение графика ---
plt.figure(figsize=(10, 6))

plt.plot(x_values, heap_times, 'o-', label='Heap Sort', linewidth=2, markersize=8)
plt.plot(x_values, bubble_times, 's-', label='Bubble Sort', linewidth=2, markersize=8)

plt.title('Сравнение времени работы сортировок', fontsize=14)
plt.xlabel('Размер данных', fontsize=12)
plt.ylabel('Время (сек)', fontsize=12)

# Логарифмическая шкала для наглядности
plt.xscale('log')
plt.yscale('log')

plt.grid(True, which="both", ls="-", alpha=0.3)
plt.legend(fontsize=12)
plt.tight_layout()
plt.show()
