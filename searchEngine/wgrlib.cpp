#include <bits/stdc++.h>
#include "./tinyxml.h"
#include "./tinystr.h"
#include "wgrlib.h"

using namespace std;

map<string, pair<int, vector<string> > > g; // graph
set<pair<int, string> > top; // top
set<pair<int, string> > tBuf; // top area

void load(const char* path) {

    ifstream f(path);
    if(!f.good()) return;

    TiXmlDocument doc(path);

	if (!doc.LoadFile())
        return;

	TiXmlHandle hDoc(&doc);
	TiXmlElement* pElem;
	TiXmlHandle hRoot(0);
    vector<string> cur;

		pElem=hDoc.FirstChildElement().Element();
		// should always have a valid root but handle gracefully if it does
		if (!pElem) return;
		// save this for later
		hRoot=TiXmlHandle(pElem);

		auto site=hRoot.FirstChildElement().Element();
		if (!site) return;

		for(; site; site=site->NextSiblingElement()) {

            cur.clear();

            hRoot=TiXmlHandle(site);

            pElem=hRoot.FirstChildElement().Element();
            if (!pElem) return; // name

            auto siteName=pElem->GetText(); // site name

            // update

            pElem=pElem->NextSiblingElement(); // rating
            auto rate=pElem->GetText();

            pElem=pElem->NextSiblingElement();
            hRoot=TiXmlHandle(pElem);

            pElem=hRoot.FirstChildElement().Element();
            if (!pElem) return;

            for(; pElem; pElem=pElem->NextSiblingElement()) {
                auto gr = pElem->GetText();
                cur.push_back(gr);
            }

            g[siteName] = make_pair(stoi(rate), cur);

        }

}

void save(const char* path) {
    remove(path);

    TiXmlDocument doc;
    TiXmlElement* el;
    TiXmlDeclaration* decl = new TiXmlDeclaration( "1.0", "", "" );
    doc.LinkEndChild( decl );

    TiXmlElement* root = new TiXmlElement( "DataBase" );
    doc.LinkEndChild( root );


    for(auto it = g.begin(); it != g.end(); ++it) {

        el = new TiXmlElement( "Site" );
        root->LinkEndChild( el );
        TiXmlElement* rootSite = el;

        el = new TiXmlElement( "Name" );
        el->LinkEndChild( new TiXmlText( (it->first).c_str() ));
        rootSite->LinkEndChild( el );

        el = new TiXmlElement( "Rate" );
        el->LinkEndChild( new TiXmlText( to_string(it->second.first).c_str() ));
        rootSite->LinkEndChild( el );

        TiXmlElement* links = new TiXmlElement( "Links" );
        rootSite->LinkEndChild( links );

        auto vEnd = it->second.second.end();
        for(auto vSt = it->second.second.begin(); vSt != vEnd; ++vSt) {

            el = new TiXmlElement( "Name" );
            el->LinkEndChild( new TiXmlText( (*vSt).c_str() ));
            links->LinkEndChild( el );

        }

    }
    doc.SaveFile(path);

}

void add(const string& pFilename) {

    string path="./Update/"+pFilename+".xml";
    ifstream f(path.c_str());
    if(!f.good()) {
        path="./SitesBase/"+pFilename+".xml";
        if(g.count(pFilename)) return;
    }
    TiXmlDocument doc( path.c_str() );

	if (!doc.LoadFile())
        return;

	TiXmlHandle hDoc(&doc);
	TiXmlElement* pElem;
	TiXmlHandle hRoot(0);


		pElem=hDoc.FirstChildElement().Element();
		// should always have a valid root but handle gracefully if it does
		if (!pElem) return;
		// save this for later
		hRoot=TiXmlHandle(pElem);

		pElem=hRoot.FirstChildElement().Element();
		if (!pElem) return;

		auto siteName=pElem->GetText(); // site name

            // update
            vector<string> cur;

            pElem=pElem->NextSiblingElement(); // rating
            auto rate=pElem->GetText();

            pElem=pElem->NextSiblingElement();
            hRoot=TiXmlHandle(pElem);

            pElem=hRoot.FirstChildElement().Element();
            if (!pElem) return;

            for(; pElem; pElem=pElem->NextSiblingElement()) {
                auto gr = pElem->GetText();
                cur.push_back(gr);
            }

            g[siteName] = make_pair(stoi(rate), cur);

            path="./Update/"+pFilename+".xml";
            remove(path.c_str());

}

void dfs(const string& site, int depth) {
    if(!depth) return;
    auto itEnd = g[site].second.end();
    for(auto it = g[site].second.begin(); it != itEnd; ++it) {
        add(*it);
        auto r = g[*it].first;
        if(!tBuf.count(make_pair(r, *it))) {
            tBuf.insert(make_pair(r, *it));
            dfs(*it, depth-1);
        }
    }
}

void area(const string& site, int depth) {
    tBuf.clear();
    add(site);
    cout << "\n\n\n#######################__" << site << ' ' << "AREA__######################\n\n\n";
    dfs(site, depth);
    if(tBuf.empty()) return;
    auto it = tBuf.end(); --it;
    for(;it != tBuf.begin(); --it)
        cout << it->second << ' ' << it->first << "\n\n";
    if(!tBuf.empty())
        cout << it->second << ' ' << it->first << "\n\n";
    cout << "\n######################################################\n\n\n";
}

void updTop() {
    top.clear();
    for(auto it = g.begin(); it != g.end(); ++it)
        top.insert(make_pair(it->second.first, it->first));
}

void topF(int i) {
    updTop();
    cout << "\n\n\n######################__TOP" << i << "__######################\n\n\n";
    if(top.empty()) return;
    auto it = top.end(); --it;
    for(; it != top.begin() && i; --it, --i)
        cout << it->second << ' ' << it->first << "\n\n";
    if(i && !top.empty()) {
        cout << it->second << ' ' << it->first << "\n\n";
    }
    cout << "\n######################################################\n\n\n";
}

void clr(const char* path) {
    g.clear();
    top.clear();
}

void handler(const string& input,
        string& option, int& depth, string& s) {
    string words[3];
    int k = 0;
    for(size_t i = 0; i < input.length(); ++i) {
        if(input[i] == ' ')
            ++k;
        else words[k] += input[i];
    }
    option = words[0];
    s = words[2];
    if(k) depth = stoi(words[1]);
}

void stop() {
    save();
    exit(0);
}

void go() {
    string input, option, s;
    int depth = 3;
    getline(cin, input);
    handler(input, option, depth, s);
    if(option == "exit") stop();
    else if(option == "clear") clr();
    else if(option == "top") topF(depth);
    else if(option == "area") area(s, depth); // area depth site
    else add(input);
}
