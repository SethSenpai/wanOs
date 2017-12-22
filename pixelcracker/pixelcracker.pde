PImage img;
PrintWriter output;
int counter = 0;
boolean startP = false;

void setup(){
  size(550,550);
  frameRate(2);
  background(39);
}

void draw() {
  background(39);
  
  if(img != null){ 
    image(img,0,0);
    if(startP){
    img.loadPixels();
    for (int y = 0; y < img.height; y++){
      for (int x = 0; x < img.width; x++){
        int loc = x + y*img.width;
        color c = img.pixels[loc];
        float r = red(c);
        float g = green(c);
        float b = blue(c);
        if(r < 10 && g < 10 && b < 10){
          println(x + "," + y);
          if(counter != 0){
          output.print(",{"+x+","+y+"}");
          }
          else{
          output.print("{"+x+","+y+"}");
          }
          counter++;
        }
      }
    }
    startP = false;
    output.println("}");
    output.println("total number of pixels: " + counter);
    counter = 0;
    output.flush(); // Writes the remaining data to the file
    output.close();
    }
  }
  fill(39);
  rect(0,520,550,200);
  fill(255);
  text("ENTER to select a file, SPACE to start processing it.",10,540);
}


void keyPressed(){
  if(key == ENTER){ 
  selectInput("Select a file to process:", "fileSelected");
  }
  if(key == ' '){
  startP = true;
  }
}

void fileSelected(File selection) {
  if (selection == null) {
    println("Window was closed or the user hit cancel.");
  } else {
    println("User selected " + selection.getAbsolutePath());
    img = loadImage(selection.getAbsolutePath());
    String[] filename = split(selection.getAbsolutePath(), '\\');
    String fname = filename[filename.length - 1];
    //println(fname);
    output = createWriter(fname+".txt");
    output.print("{");
  }
}