#include<bits/stdc++.h>
using namespace std;

enum Type
{
    IMAGE,TEXT
};

class DocumentChunk
{
    private:
        string data;
        Type documentType;
    public:
        DocumentChunk(string data,Type documentType)
        {
            this->data=data;
            this->documentType=documentType;
        }
        string getData()const{return this->data;}
        Type getType()const{return this->documentType;}

        void setData(string data){this->data=data;}
};
class Compare {
public:
    bool operator()(const DocumentChunk& a, const DocumentChunk& b) {
        return a.getData().length() > b.getData().length();
    }
};
class ToolCallModel
{
    public:
        static string CallTool(const DocumentChunk& documentChunk)
        {
            if(documentChunk.getType()==IMAGE)
            {
                //call model 1
            }
            else
            {
                //call model 2
            }
            return documentChunk.getData();
        }
};
class DocumentProcessor
{
    private:
        //will store processed chunks in the same array
        vector<DocumentChunk>chunksText,chunksImage;
    public:
        DocumentProcessor()
        {
            chunksImage.clear();
            chunksText.clear();
        }
        vector<DocumentChunk>getChunksText(){return this->chunksText;}
        void processChunks()
        {
            for(int chunkIdx=0;chunkIdx<chunksText.size();chunkIdx++)
            {
                chunksText[chunkIdx].setData(ToolCallModel().CallTool(chunksText[chunkIdx]));
            }
            for(int chunkIdx=0;chunkIdx<chunksImage.size();chunkIdx++)
            {
                chunksImage[chunkIdx].setData(ToolCallModel().CallTool(chunksImage[chunkIdx]));
            }
        }
        DocumentChunk combineChunks()
        {
            priority_queue<DocumentChunk,vector<DocumentChunk>,Compare>
            priorityChunksImage,priorityChunksText;

            for(auto chunk:chunksImage)
                priorityChunksImage.push(chunk);
            for(auto chunk:chunksText)
                priorityChunksText.push(chunk);

            if(priorityChunksText.empty() && priorityChunksImage.empty())
                return DocumentChunk("", TEXT);

            if(priorityChunksText.empty())
                return priorityChunksImage.top();

            if(priorityChunksImage.empty())
                return priorityChunksText.top();
            
            while(!priorityChunksImage.empty() && priorityChunksImage.size()>1)
            {
                DocumentChunk documentChunkTop1=priorityChunksImage.top();
                priorityChunksImage.pop();
                    
                DocumentChunk documentChunkTop2=priorityChunksImage.top();
                priorityChunksImage.pop();
                string combinedData=documentChunkTop1.getData()+documentChunkTop2.getData();
                DocumentChunk combinedChunk(combinedData,IMAGE);
                
                priorityChunksImage.push(DocumentChunk(ToolCallModel().CallTool(combinedChunk),IMAGE));
            }
            while(!priorityChunksText.empty() && priorityChunksText.size()>1)
            {
                DocumentChunk documentChunkTop1=priorityChunksText.top();
                priorityChunksText.pop();
                    
                DocumentChunk documentChunkTop2=priorityChunksText.top();
                priorityChunksText.pop();
                string combinedData=documentChunkTop1.getData()+documentChunkTop2.getData();
                DocumentChunk combinedChunk(combinedData,TEXT);
                
                priorityChunksText.push(DocumentChunk(ToolCallModel().CallTool(combinedChunk),TEXT));
            }
            
            string fullCombinedData=priorityChunksText.top().getData()+priorityChunksImage.top().getData();
            DocumentChunk fullDocumentChunk(fullCombinedData,TEXT);

            return  DocumentChunk(ToolCallModel().CallTool(fullDocumentChunk),TEXT);
        }

};
class Document
{
    private:
        DocumentProcessor documentProcessor;
        string uploadedDocument;
    public:
        Document(string uploadedDocument){this->uploadedDocument=uploadedDocument;}

        string generateSummary()
        {
            documentProcessor.processChunks();
            DocumentChunk result = documentProcessor.combineChunks();
            return result.getData();
        }

};