//Applet Life Cycle Example

    /*
            Applet Life Cycle Example
            This java example explains the life cycle of Java applet.
    */
     
    import java.applet.Applet;
    import java.awt.Graphics;
     
    /*
     *
     * Applet can either run by browser or appletviewer application.
     * Define <applet> tag within comments as given below to speed up
     * the testing.
     */
     
    /*
    <applet code="AppletLifeCycleExample" width=100 height=100>
    </applet>
    */
     
     
    public class AppletLifeCycleExample extends Applet{
     
           
            /*
             * init method is called first.
             * It is used to initialize variables and called only once.
             */
            public void init() {
                    super.init();
            }
           
            /*
             * start method is the second method to be called. start method is
             * called every time the applet has been stopped.
             */
            public void start() {
                    super.start();
            }
           
            /*
             * stop method is called when the the user navigates away from
             * html page containing the applet.
             */
            public void stop() {
                    super.stop();
            }
           
            /* paint method is called every time applet has to redraw its
             * output.
             */
            public void paint(Graphics g) {
                    super.paint(g);
            }
           
            /*
             * destroy method is called when browser completely removes
             * the applet from memeory. It should free any resources initialized
             * during the init method.
             */
            public void destroy() {
                    super.destroy();
            }
     
    }
