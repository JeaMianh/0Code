package cn.edu.xidian.practise;


class Glyph 
{
  void draw() 
  { 
	  System.out.println("Glyph.draw()"); 
  }
  
  Glyph() 
  {
	  draw();
  }
}

class RoundGlyph extends Glyph 
{
	
  private int radius = 1;
  
  RoundGlyph(int r) 
  {
	  radius = r;
	  System.out.println("RG.RoundGlyph(), radius = " + radius);
  }
  
  void draw() { System.out.println("RG.draw(), radius = " + radius); }
  
}
public class PolyConstruct 
{
	public static void main(String[] args) 
	{
		new RoundGlyph(5);
	}
}


    

