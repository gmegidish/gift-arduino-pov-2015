
#define WIDTH 49
#define HEIGHT 8

static char *pixels[HEIGHT] = {
	"       x                            x            ",  // PC2 (A2/16)
	" x  x  xxx  x   x   xxx  x  x xx    xxx xxx x xx ",  // PC1 (A1/15)
	"  x  x    x  x  x      x  x x   x      x x   x  x",  // PC0 (A0/14)
	"  x  x    x x xx       x  x  x  x      x x   x  x",  // PB5 (D13)
	"  x  x   x  x  x       x  x  x x      x  x   x  x",  // PB4 (D12)
	"  x  x  x   x   x   xxxxx x  xx      x   x   x xx",  // PB3 (D11)
	"  x                                              ",  // PB2 (D10)
	"  x                                              ",  // PB1 (D9)
};

void setup() {
        DDRB = 0xff;
        DDRC = 0xff;
}

void loop() {
        for (int x=WIDTH-1; x>=0; x--) {
                for (int y=0; y<HEIGHT; y++) {
                        int c = pixels[HEIGHT-1-y][x] != ' ';
                        if (y < 3) {
                                digitalWrite(16-y, c);
                        } else {
                                digitalWrite(9+(HEIGHT-1-y), c);
                        }
                }
                
                delay(50);
        }       
}

