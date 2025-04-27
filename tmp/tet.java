package tmp;

public class tet {

    public class car {
        private int speed;
        car() {
            speed = 0;
        }

        car(int speed) {
            this.speed = speed;
        }

        private int getSpeed()10 {
            return speed;
        }

        void showspeed() {
            System.out.println(this.speed);
        }
    }

    public class vec extends car {
        vec(int speed) {
            super(speed);
        }
        
        void showspeed() {
            System.out.println("my speed is " + super.speed + 10);
        }

        void shname() {
            System.out.println("my name is vec");
        }
    }


    public static void main(String[] args) {
        tet t = new tet();
        car c = t.new vec(4);
        c.showspeed();
    }

}
