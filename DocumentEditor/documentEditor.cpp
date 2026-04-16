#include<bits/stdc++.h>
#include <string>
class DocumentElement
{
    virtual void render()=0;
};
class TextRenderElement : public DocumentElement
{   
    private:
        string renderText;
    public:
        TextRenderElement(string renderText)
        {
            this->renderText=renderText;
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
            this->renderImage=renderImage;
        }
        string render() override
        {
            return renderImage;
        }
};
class Persistance
{
    virtual void save()=0;
};
class FileStorage : public Persistance
{
    //storing in a file
};
class DbStorage : public Persistance
{
    //storing in a db
};
class Document
{
    vector<DocumentElement*>documentElements;

     void addElement(DocumentElement* documentElement)
     {
        documentElements.push_back(documentElement);
     }

    string render()
    {
        string result;
        for(auto element:documentElements)
        {
            result.push_back(element->render());
        }
        return result;
    }
};
class DocumentEditor
{
    Document*document;
    Persistance*persistance;
    string renderedDocument;

    DocumentEditor(Document*document,Persistance*persistance)
    {
        this->document=document
        this->persistance=persistance
    }
    void addElement(string text)
    {
        document->addElement(text);
    }
};