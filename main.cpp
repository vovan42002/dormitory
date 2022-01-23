#include <QtCore/QCoreApplication>
#include <type.h>

Dormitory *root;
extern char *logFileName = "log.txt";
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    SetConsoleTitleA("Project 'Dormitory',""Student Bohdan V.O., gr. KI-191");
    string s = "Project 'Dormitory' is open by ";
    s.append("Student Bohdan V.O., gr. KI-191");
    log_file(s);
    mainMenu(NULL);
    return 0;
}
