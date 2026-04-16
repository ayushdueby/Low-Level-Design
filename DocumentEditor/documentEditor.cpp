#include <bits/stdc++.h>
using namespace std;

class DocumentElement
{
public:
    virtual string render() = 0;
};

class TextRenderElement : public DocumentElement
{   
private:
    string renderText;

public:
    TextRenderElement(string renderText)
    {
        this->renderText = renderText;
    }

    string render() override
    {
        return renderText;
    }
};

class ImageRenderElement : public DocumentElement
{   
private:
    string renderImage;

public:
    ImageRenderElement(string renderImage)
    {
        this->renderImage = renderImage;
    }

    string render() override
    {
        return renderImage;
    }
};

class Persistance
{
public:
    virtual void save(string data) = 0;
};

class FileStorage : public Persistance
{
public:
    void save(string data) override
    {
        cout << "Saving to file: " << data << endl;
    }
};

class DbStorage : public Persistance
{
public:
    void save(string data) override
    {
        cout << "Saving to DB: " << data << endl;
    }
};

class Document
{
private:
    vector<DocumentElement*> documentElements;

public:
    void addElement(DocumentElement* documentElement)
    {
        documentElements.push_back(documentElement);
    }

    string render()
    {
        string result;
        for (auto element : documentElements)
        {
            result += element->render();   // FIXED
        }
        return result;
    }
};

class DocumentEditor
{
private:
    Document* document;
    Persistance* persistance;

public:
    DocumentEditor(Document* document, Persistance* persistance)
    {
        this->document = document;
        this->persistance = persistance;
    }

    void addText(string text)
    {
        document->addElement(new TextRenderElement(text));
    }

    void addImage(string image)
    {
        document->addElement(new ImageRenderElement(image));
    }

    void save()
    {
        string renderedDocument = document->render();
        persistance->save(renderedDocument);
    }
};