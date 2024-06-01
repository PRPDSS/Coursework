/* Текст песни, чтоб нескучно было
Слева, справа смотри
Не поймешь, что внутри
Вот таки чудеса
Сам ни свой, свой ни сам.
А Земля да трещит
А на сердце легко
Потому медный шит
Потому медный лоб
Приглядишься ли
Близко ль, издали
Все как будто ни так
И лицо и душа
Видно впрямь у него
Тут вы были правы
Или мыслей нет
Или нет головы
А он шел себе по свету насвистывал
Из коры себе подругу выстругал
Лесами темными, реками быстрыми
А он шел себе по свету насвистывал
Он не понят, да
Искрой тронут, да
Вот такая судьба
Вытирай пот со лба
Видно впрямь у него
Тут вы были правы
Или мыслей нет
Или нет головы
А он шел себе по свету насвистывал
Из коры себе подругу выстругал
Лесами темными, реками быстрыми
А он шел себе по свету насвистывал
Думу думай, кричи
Во все двери стучи
Во все двери стучи
Рукава засучи
А проснуться бы
Только это не сон
Мы столбом стоим
А он, а он, а он...
А он шел себе по свету насвистывал
Из коры себе подругу выстругал
Лесами темными, реками быстрыми
А он шел себе по свету насвистывал
Всем прохожим твердил,
Что по небу ходил.
Что по небу ходил
Да ангелов видел
Видно впрямь у него
Тут вы были правы
Или мыслей нет
Или нет головы...
*/

#include <utility>
class Equation
{
    double a, b, c;
    double root1, root2;

public:
    Equation() : a(0), b(0), c(0){};
    Equation(const double &a, const double &b, const double &c) : a(a), b(b), c(c){};
    void setValues(const double &a, const double &b, const double &c)
    {
        this->a = a;
        this->b = b;
        this->c = c;
    }
    void setRoots(const std::pair<double, double> &roots)
    {
        this->root1 = roots.first;
        this->root2 = roots.second;
    }
    const double getA() const { return a; }
    const double getB() const { return b; }
    const double getC() const { return c; }
    const std::pair<double, double> getRoot() const { return std::pair<double, double>(root1, root2); }
};

class Solver
{
public:
    void discriminant(Equation *e)
    {
        const double d = pow(e->getB(), 2) - e->getA() * e->getB() * 4;
        std::pair<double, double> ans;
        if (d == 0)
        {
            ans.first = -e->getB() / 2;
            ans.second = ans.first;
            e->setRoots(ans);
            return;
        }
        if (d > 0)
        {
            ans.first = (-e->getB() + sqrt(d)) / 2;
            ans.second = (-e->getB() - sqrt(d)) / 2;
            e->setRoots(ans);
            return;
        }
    }
};