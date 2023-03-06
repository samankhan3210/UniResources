#include"Editor.h"

Editor::Editor()
{
}
Editor::Editor(string id, string name):Employee(id, name)
{
}
void Editor::receiveNews(string news)
{
    this->news = news;
    sed = new SubEditor("sub123","Usama");
    this->news = sed->editNews(this->news);
}
void Editor::approveNews()
{
    //conditions for approval whether to accept or reject the report
    cout<<"APPROVED";
}