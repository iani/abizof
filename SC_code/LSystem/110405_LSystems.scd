/*
\LSystem and Event - enviroment study
Quarks.gui
Aris Bezas Tue, 05 April 2011, 10:15
*/

//:e Compile the Enviroment
(
e = (
	initString: "F-F", 		// Initial string for substitution
	subString: "F[F]", 		// Substitution string
	doos: 4, 					// Recurcions	
	thetaStep: 1, 			// step
	lengthStep: 0.01, 
	rate: 1, 
	length: 10, 
	theta: 0, 
	addr: NetAddr.localAddr);

e use: { 
	k = Task({
		loop  { 
			l= RedLSystem(~initString, ($F: ~subString));		
			t = RedLTurtle(l, ~length, ~theta, 1, 0);
			~doos do: {
				l.next;
			};
			~addr.sendMsg("lsystem", l.asString, t.length, t.theta, t.scale, t.noise, l.generation);
			~theta = ~theta + ~thetaStep;
			~length = ~length + ~lengthStep;
			~rate.wait;
		}
	})
}
);
p = Task({ 
		500.do({ arg i;
			OF.lsystem("translate",i,2*i);
			0.02.wait 
		}); 
	});

c = Task({
		255.do({|i|
			OF.lsystem("rgb",2,2,2,2);
			0.02.wait;
			})
	});
//:c color
c.start
//:b Control background colors at OF

OF.int("rBack", 55);
OF.int("gBack", 55);
OF.int("bBack", 55);
OF.int("aBack", 20);
OF.lsystem("rgb", 0,0,0,30);

//:t Translate
OF.lsystem("translate",0,400)
OF.lsystem("translate", "center");

p.start;
//p.pause;
//p.resume;
//p.reset;
//p.stop;


//:l lsystem
k.start;	// Start the Task
//k.pause;
//k.stop;
e[\rate] = 0.02;	//	define the rate
e[\addr] = NetAddr("127.0.0.1", 12345);  //localhost, oF port
e[\initString] = "F";
e[\thetaStep]= 100;
e[\subString] = "F-F++F-F";
e[\theta] = 0;
e[\length] = 10;
e[\doos] = 4;

//:k koch curve
(
e[\addr] = NetAddr("127.0.0.1", 12345);  //localhost, oF port
e[\initString] = "F";
e[\thetaStep]= 0.1;
e[\subString] = "F-F++F-F";
e[\theta] = 60;
e[\length] = 20;
e[\doos] = 4;
)
//:h big h
(
e[\addr] = NetAddr("127.0.0.1", 12345);  //localhost, oF port
e[\initString] = "[F]--F";
e[\subString] = "|[+F][-F]-F";
e[\theta] = 0;
e[\length] = 40;
e[\doos] = 3;
e[\thetaStep]=1;

)
//:g twig
(
e[\addr] = NetAddr("127.0.0.1", 12345);  //localhost, oF port
e[\initString] = "F";
e[\subString] = "|[-F][+F]";
e[\theta] = 20;
e[\length] = 70;
e[\doos] = 6;
)
//:w weed 1
(
e[\addr] = NetAddr("127.0.0.1", 12345);  //localhost, oF port
e[\initString] = "F-";
e[\subString] = "-F-F[-F]F[+F]F";
e[\theta] = 25;
e[\length] = 40;
e[\doos] = 3;
)


//:s GUI
(
w = Window.new("Control theta step",Rect(300,Window.screenBounds.height-300,400,100)).front;
a = Slider(w, Rect(50, 20, 300, 40))
	.value_(0.5)
	.step_(0.005)
	.focus
	.action_({
		e[\thetaStep]=(a.value-0.5)*2;
		//e[\thetaStep].postln;
	})
)

/*
(

w = Window.new.front;
a = Slider(w, Rect(20, 10, 150, 20));
a.action = { e[\thetaStep]=(a.value-0.5)*2 };
)
*/