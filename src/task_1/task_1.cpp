#include "task_1.hpp"

int random_invert_byte(float Q /* вероятность */, int byte)
{
    return (rand() % 10) >= static_cast<int>(Q * 10) ? byte ^ 1 : byte;
}
int correct_msg_checker(int* byte_array, int array_size)
{
    int result_byte = byte_array[0];
    for(size_t i = 1; i <= array_size; i++)
    {
        result_byte ^= byte_array[i];
    }
    return result_byte;
}

bool task_1()
{
    const int BYTE_ARRAY_SIZE {4};
    const float Q {0.5}; // вероятность
    std::cout << "Введите " << BYTE_ARRAY_SIZE << " последовательных бита:" << std::endl;
    int* byte_array {new int[BYTE_ARRAY_SIZE]};
    for(size_t i = 0; i <= BYTE_ARRAY_SIZE - 1; i++)
    {
        std::cin >> byte_array[i];
    }
    std::cout << "Введеная вами последовательность:" << std::endl;
    for(size_t i = 0; i <= BYTE_ARRAY_SIZE - 1; i++)
    {
        std::cout << byte_array[i] << std::endl;
    }
    std::cout << "Вычисление контрольного " << BYTE_ARRAY_SIZE << " бита путем сложения по модулю два всех бит последовательнсти" << std::endl;
    byte_array[BYTE_ARRAY_SIZE] = byte_array[0];
    for(size_t i = 1; i <= BYTE_ARRAY_SIZE - 1; i++)
    {
        byte_array[BYTE_ARRAY_SIZE] ^= byte_array[i];
    }
    std::cout << "Результирующий "<< BYTE_ARRAY_SIZE + 1 << " - ый бит равен: " <<  byte_array[BYTE_ARRAY_SIZE] << std::endl;
    srand(time(0));
    for(size_t i = 0; i <= BYTE_ARRAY_SIZE; i++)
    {
        byte_array[i] = random_invert_byte(Q, byte_array[i]);
    }
    std::cout << "Инвертируемая последовательность - " << std::endl;
    for(size_t i = 0; i <= BYTE_ARRAY_SIZE; i++)
    {
        std::cout << byte_array[i] << std::endl;
    }
    std::cout << "Проверка " << BYTE_ARRAY_SIZE + 1 << " - ти битов..." << std::endl;
    if (!correct_msg_checker(byte_array, BYTE_ARRAY_SIZE))
    {
        std::cout << "Ошибка. Результат равен единице" << std::endl;
    }
    else
    {
        std::cout << "Успех. Результат равен нулю" << std::endl;
    }
    return true;
}