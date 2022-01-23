#include <QtCore/QCoreApplication>
#include <type.h>

Dormitory *root;
char *logFileName = "log.txt";
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    SetConsoleTitleA("Project 'Dormitory',""Student Bohdan V.O., gr. KI-191");

    return a.exec();
}
