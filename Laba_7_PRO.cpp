#include <cilk/cilk.h>
#include <cilk/reducer_opadd.h> cilk::reducer_opadd<int> sum;
void addsum()
{
sum += 1;
}
int main()
{
sum += 1;
cilk_spawn addsum();
sum += 1; /* �������� sum � ���� ������ �������� �� ���������� ������
���������� */
cilk_sync;
return sum.get_value();
} 