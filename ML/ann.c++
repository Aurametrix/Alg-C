[Serializable]
struct PreInput
{
    public double Value;
    public double[] Weights;            
};

[Serializable]
struct Input
{
    public double InputSum;                
    public double Output;                
    public double Error;                
    public double[] Weights;        
};
            
[Serializable]        
struct Hidden        
{                
    public double InputSum;                    
    public double Output;                
    public double Error;                
    public double[] Weights;        
};
            
[Serializable]        
struct Output<T> where T : IComparable<T>         
{                
    public double InputSum;                
    public double output;                
    public double Error;                
    public double Target;     
    public T Value;   
};
