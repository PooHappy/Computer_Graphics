#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <vector>
#include <GL/glut.h>

using namespace std;
struct BitMapFile
{
    int sizeX;
    int sizeY;
    unsigned char* data;
}; 
BitMapFile* getBMPData(string filename)
{
    BitMapFile* bmp = new BitMapFile;
    unsigned int size, offset, headerSize;

    ifstream infile(filename.c_str(), ios::binary);

    infile.seekg(10);
    infile.read((char*)&offset, 4);

    infile.read((char*)&headerSize, 4);

    infile.seekg(18);
    infile.read((char*)&bmp->sizeX, 4);
    infile.read((char*)&bmp->sizeY, 4);

    size = bmp->sizeX * bmp->sizeY * 24;
    bmp->data = new unsigned char[size];

    infile.seekg(offset);
    infile.read((char*)bmp->data, size);

    int temp;
    for (int i = 0; i < size; i += 3)
    {
        temp = bmp->data[i];
        bmp->data[i] = bmp->data[i + 2];
        bmp->data[i + 2] = temp;
    }

    return bmp;
}

void Display()
{
    float vertex[10][9] = { -1 };
    float normal[7][3] = { -1 };
    float face[7][5] = { -1 };
    float Coo[8] = { 0,0,0,1,1,1,1,0 };
    float Coo4[10] = { 0,0,0.9,0,0.9,0.6,0.45,1,0,0.6 };
    vector<float> arrV;
    vector<float> arrN;
    vector<float> arrF;
    int count = 0;
    arrV = { 0,0,0, 1,0,0, 1,1,0, 0.5,1.5,0 ,0,1,0, 0,0,1 ,1,0,1 ,1,1,1, 0.5,1.5,1 ,0,1,1 };
    arrN = { -1,0,0 ,-0.707,0.707,0, 0.707,0.707,0, 1,0,0, 0,-1,0, 0,0,1, 0,0,-1 };
    arrF = { 0,5,9,4, 3,4,9,8, 2,3,8,7, 1,2,7,6, 0,1,6,5, 5,6,7,8,9, 0,4,3,2,1 };
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 3; j++) {
            vertex[i][j] = arrV.at(j + count);
        }
        count += 3;
    }
    count = 0;
    for (int i = 0; i < 7; i++) {
        for (int j = 0; j < 3; j++) {
            normal[i][j] = arrN.at(j + count);
        }
        count += 3;
    }
    count = 0;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 4; j++) {
            face[i][j] = arrF.at(j + count);
        }
        count += 4;
    }
    for (int i = 5; i < 7; i++) {
        for (int j = 0; j < 5; j++) {
            face[i][j] = arrF.at(j + count);
        }
        count += 5;
    }

    glClearColor(0.0, 0.0, 0.0, 0.0);
    glShadeModel(GL_FLAT);
    glEnable(GL_DEPTH_TEST);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    gluLookAt(5, 5, 5, 0, 0, 0, 0.0, 1, 0.0);

    BitMapFile* image;

    image = getBMPData("canTop.bmp");

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glEnable(GL_TEXTURE_2D);
    glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);

    glPixelStorei(GL_UNPACK_ALIGNMENT, 1);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_TEXTURE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_TEXTURE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, image->sizeX,
        image->sizeY, 0, GL_RGB, GL_UNSIGNED_BYTE,
        image->data);


    int c = 0;
    for (int i = 0; i < 5; i++) {
        glBegin(GL_POLYGON);
        for (int j = 0; j < 4; j++) {
            glNormal3f(normal[i][0], normal[i][1], normal[i][2]);
            int pos = face[i][j];
            glTexCoord2f(Coo[c], Coo[c+1]);
            glVertex3f(vertex[pos][0], vertex[pos][1], vertex[pos][2]);
            c += 2;
        }
        c = 0;
        glEnd();
    }
    for (int i = 5; i < 7; i++) {
        glBegin(GL_POLYGON);
        for (int j = 0; j < 5; j++) {
            glNormal3f(normal[i][0], normal[i][1], normal[i][2]);
            int pos = face[i][j]; 
            glTexCoord2f(Coo4[c], Coo4[c+1]);
            glVertex3f(vertex[pos][0], vertex[pos][1], vertex[pos][2]);
            c += 2;
        }
        c = 0;
        glEnd();
    }
    glFlush();

}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(900, 900);
    glutInitWindowPosition(300, 300);
    glutCreateWindow("2");
    glutDisplayFunc(Display);
    glMatrixMode(GL_PROJECTION);
    glFrustum(-1.5, 1.5, -1.5, 1.5, 5, 10);
    glutMainLoop();
    return(0);
}