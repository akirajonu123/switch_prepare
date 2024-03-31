#include <iostream>
using namespace std;

class XMLData {
    string xmlData;
public:
    XMLData(string pXmlData){
        xmlData = pXmlData;
    }    
    string getXMLData(){
        return xmlData;
    }

};

class DataAnalyticsTool{
    string jsonData;
public:
    DataAnalyticsTool(){}
    DataAnalyticsTool(string pJsonData){
        jsonData = pJsonData;
    }
    virtual void analyseData(){
        cout<<"Analysing this perticular data"<<jsonData<<endl;
    }
};

class Client{
public:
    void ProcessData(DataAnalyticsTool* tool)
    {
        tool->analyseData();
    }
};

class Adapter : public DataAnalyticsTool{
    
    XMLData* xmlData;
    public:
        Adapter(XMLData* pXMLData){
            xmlData = pXMLData;
        }
         void analyseData() override{
        cout<<"Convert XML Data"<<xmlData->getXMLData()<<"to Json Data"<<endl;
        cout<<"Analysing the coverted JSON data"<<endl;
    }
};

int main()
{
    XMLData* xmlData = new XMLData("Sample XML data");
    DataAnalyticsTool* tool = new Adapter(xmlData);
    Client* client = new Client;
    client->ProcessData(tool);
    return 0;
}