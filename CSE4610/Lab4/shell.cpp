Shell::Shell(string filename, int numberofblocks, int blocksize): filesys(diskname, numberofblocks, blocksize)
{
}


int Shell::dir()
{
    vector<string> flist = ls();
    
    for( int i=0; i< flist.size(); ++i)
    {
          cout<<flist[i]<<endl;;
    }
    return 1;

}

int Shell::add(string file, string buffer)
{

    int error = newfile(file)
    
    if(error < 1)
    {
       cout<<"Sorry."<<endl;
    }

    vector<string> blocks =block(buffer, getblocksize());
   
    for(int i =0; i<blocks.size(); i++)
    {
       addblock(file, blocks[i]);
    }

    return 1;
     

}

int Shell::del(string file)
{

    int code = getfirstblock(file);
    
    if(code==1)
    {
       cout<<"No such file"<<endl;
       return;
    }
    
    while(getfirstblock(file) !=0)
    {
       delblock(file, getfirstblock(file));
     
    }
    rmfile(file);

}

int Shell::type(string file)
{
     int block = getfirstblock(file);
     while( block>0)
     {
          delblock(file,block);
          block = getfirstblock(file);
     }

     return rmfile(file);

}


int Shell::copy(string file1, string file2)
{
     int block = getfirstblock(file1);
     if(block == -1)
     {
          cout<<"No such file"<<endl;
          return 0;
     }
     
     block=getfirstblock(file2);
     if(block>=0)
     {
           cout<<"Destination File Exists"<<endl;
           return 0;
     }

     newfile(file2);
     int block=getfirstblock(file1);
     while(block!=0)
     {
         string buffer;
         readblock(file1, block, buffer);
         addblock(file2, buffer);
         block=nextblock(file1,block);
     }
  
     return 1;
}

