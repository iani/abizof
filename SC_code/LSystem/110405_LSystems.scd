/*
LSystem and Event - enviroment study
Quarks.gui
Aris Bezas Tue, 05 April 2011, 10:15
*/

Environment 	// cmd+D
(
e = (
	initString: "F-F", 		// Initial string for substitution
	subString: "F[F]", 		// Substitution string
	doos: 4, 					// Recurcions	
	thetaStep: 10, 			// step
	lengthStep: 0.01, 
	rate: 1, 
	length: 13, 
	theta: 60, 
	addr: NetAddr.localAddr);

e use: { 
	k = Task({
		loop  { 
			l= RedLSystem(~initString, ($F: ~subString));		
			t = RedLTurtle(l, ~length, ~theta, 1);
			~doos do: {
				l.next;
			};
			~addr.sendMsg("/lsystem", l.asString, t.length, t.theta, t.scale, t.noise, l.generation);
			~theta = ~theta + ~thetaStep;
			~length = ~length + ~lengthStep;
			~rate.wait;
		}
	})
}
)

// Control background colors at OF
OF.rgb("rBack",0)
OF.rgb("gBack",0)
OF.rgb("bBack",0)
OF.rgb("aBack",20)

k.start;	// Start the Task
e[\rate] = 0.05;	//	define the rate

// koch curve
(
e[\addr] = NetAddr("127.0.0.1", 12345);  //localhost, oF port
e[\initString] = "F";
e[\thetaStep]=10.1;
e[\subString] = "F-F++F-F";
e[\theta] = 60;
e[\length] = 20;
e[\doos] = 4;
)
//--big h
(
e[\addr] = NetAddr("127.0.0.1", 12345);  //localhost, oF port
e[\initString] = "[F]--F";
e[\subString] = "|[+F][-F]";
e[\theta] = 110;
e[\length] = 80;
e[\doos] = 6;
)
//--twig
(
e[\addr] = NetAddr("127.0.0.1", 12345);  //localhost, oF port
e[\initString] = "F";
e[\subString] = "|[-F][+F]";
e[\theta] = 20;
e[\length] = 70;
e[\doos] = 6;
)
//--weed 1
(
e[\addr] = NetAddr("127.0.0.1", 12345);  //localhost, oF port
e[\initString] = "F";
e[\subString] = "-F-F[-F]F[+F]F";
e[\theta] = 25;
e[\length] = 40;
e[\doos] = 3;
)



























///////////

o = NetAddr("localhost", 46100);
o.sendMsg("/initString", "F-F-F");
o.sendMsg("/subString", "F[F]-F+F[--F]+F-F");
o.sendMsg("/subString", "");
o.sendMsg("/theta", 30);
o.sendMsg("/thetaStep", 1);
o.sendMsg("/lengthStep", 0.1);
o.sendMsg("/startPosDefault");
k = Task({
		loop  { 
		o.sendMsg("/startPos", 600,500,0);
			0.1.wait;
		}
})
k.start	
k.stop

Sendmidi.new
e.free
l.stop;
\doos] = 3;

//	Basic Initial
(
e[\addr] = NetAddr("127.0.0.1", 46100);  //localhost, oF port
e[\initString] = "F-F-F-F";
e[\subString] = "F[F]-F+F[--F]+F-F";
e[\theta] = 20;
e[\length] = 50;
e[\thetaStep] = 1;
e[\lengthStep] = 0.01;
e[

e.reset
e.reject{}

// test
(
e[\addr] = NetAddr("127.0.0.1", 57120);  //localhost, oF port
e[\initString] = "F";
e[\subString] = "F-F++F-F";
e[\theta] = 60;
e[\length] = 20;
e[\doos] = 0;
)


