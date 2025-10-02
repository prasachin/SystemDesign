#include <bits/stdc++.h>
using namespace std;


// Here i am following all the design principles , i.e SOLID 

class DocumentElement
{
public:
    virtual string render() = 0;
};

class TextElement : public DocumentElement
{
private:
    string text;

public:
    TextElement(string text)
    {
        this->text = text;
    }
    string render() override
    {
        return text;
    }
};

class ImgElement : public DocumentElement
{
private:
    string path;

public:
    ImgElement(string path)
    {
        this->path = path;
    }

    string render() override
    {
        return "[Image :]" + path;
    }
};

class Document
{
private:
    vector<DocumentElement *> elements;

public:
    void addElement(DocumentElement *el)
    {
        elements.push_back(el);
    }

    string render()
    {
        string ans = "";
        for (int i = 0; i < elements.size(); i++)
        {
            ans += " " + elements[i]->render() + " ";
        }
        return ans;
    }
};

class Persistance
{
public:
    void virtual save(string data) = 0;
};

class Savetofile : public Persistance
{
public:
    void save(string data) override
    {
        cout << "Your document " << data << " saved to file. " << endl;
    }
};

class SavetoDB : public Persistance
{
public:
    void save(string data) override
    {
        cout << "Your document " << data << " saved to DB. " << endl;
    }
};

class DocumenEditor
{
private:
    Document *document;
    Persistance *storage;
    string rendereddoc;

public:
    DocumenEditor(Document *doc, Persistance *storage)
    {
        this->document = doc;
        this->storage = storage;
    }
    void addTExt(string text)
    {
        document->addElement(new TextElement(text));
    }

    void addImage(string path)
    {
        document->addElement(new ImgElement(path));
    }

    string renderedDoc()
    {
        return document->render();
    }

    void Savedoc()
    {
        storage->save(renderedDoc());
    }
};

int main()
{
    Document *document = new Document();
    Persistance *storage = new SavetoDB();
    DocumenEditor *editor = new DocumenEditor(document, storage);

    editor->addTExt("Hello world");
    editor->addImage("Picture.img");
    cout << editor->renderedDoc();
    editor->Savedoc();
    return 0;
}