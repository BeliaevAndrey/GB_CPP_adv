/*
Задание 2. Захват заголовка веб-страницы

Что нужно сделать
Запросите с сервера HTML-страницу. Для этого изучите документацию о запросах,
поддерживаемых сервисом httpbin.org/html. Найдите там запрос, который выдаёт
именно HTML-страницу. Затем сделайте запрос, явным образом используя заголовок
accept: text/html. В полученном ответе найдите заголовок статьи и выведите его
в консоль.

Рекомендации
Заголовок статьи размещается между HTML-тегами <h1></h1>. Для доступа к тексту
ответа вам потребуется метод text класса cpr::Response. Для поиска по тексту
нужных HTML-тегов лучше использовать метод find.
*/

#include <iostream>

#include <cpr/cpr.h>


std::string address("http://httpbin.org/");

std::string findTextHeader(cpr::Response& r) {
    int start = r.text.find("<h1>");
    int end = r.text.find("</h1>");

    std::string head = r.text.substr(start + 4, end - start);

    return head;
}

int main()
{
    cpr::Response response = cpr::Get(cpr::Url(address + "html"),
        cpr::Header({ {"Accept", "text/html"} }));

    std::cout << ::findTextHeader(response) << std::endl;

    return 0;
}