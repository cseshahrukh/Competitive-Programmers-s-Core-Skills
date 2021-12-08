int parent [100005]; 
vector <int> present; 

int edg; 

void initialize (int n) {
  for(int i=1; i<=n; i++)
    parent[i]=1;
  
}

int find (int x)
{
  if (parent[x]==x)
    return x; 
  return parent[x]=find(parent[x]); 
}

int union1 (int i, int sum)
{
  int x, y; 
  x=find(edges[i].src); 
  y=find(edges[i].dest); 
  
  if (x!=y)
  {
    parent[x]=y; 
    present.pb(i); 
    sum+=edges[i].weight;
  }
  
  return sum; 
  
}

int union2 (int i, int sum)
{
  int x, y; 
  x=find(edges[i].src); 
  y=find(edges[i].dest); 
  
  if (x!=y)
  {
    parent[x]=y; 
    
    sum+=edges[i].weight;
    edg++; 
  }
  
  return sum; 
  
}

int main()
{
  ...
    ...
    .... //edges sorted 
    
   int sum=0; 
  
  for(int i=0; i<E; i++)
  {
    sum=union1(i, sum); 
  }
  
  int secondMST=INT_MAX; 
  sum=0; 
  for(int j=0; j<present.size(); j++)
  {
    initialize(V); 
    edg=0; 
    for(int i=0; i<E; i++)
    {
      if (i==present[j])
        continue; 
      sum=union2(i,sum); 
    }
    
    if (edg!=V-1)
    {
      sum=0; 
      continue; 
    }
    if (secondMST>sum)
      secondeMST=sum; 
    sum=0; 
  }
  
}
  
  
  
  
  
  
  
  
  
  
  
  
  
