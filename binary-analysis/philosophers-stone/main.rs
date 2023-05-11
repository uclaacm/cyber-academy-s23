use std::io::{self, Write, Read, Cursor};

fn main() {
    io::stdout().write(b"apparently rust is so confident in its security that stack protectors are disabled by default!\ngive me some silver and I'll turn it to gold > ").unwrap();
	io::stdout().flush().unwrap();

	let mut buf = [0u8; 32];
	let mut buf = Cursor::new(unsafe {
		std::slice::from_raw_parts_mut(&mut buf as *mut _, 64)
	});
	io::stdin().lock().bytes().map(Result::unwrap).take_while(|x| *x != '\n' as u8).for_each(|x| { buf.write(&[x]).unwrap(); });
	let written = buf.position() as usize;
	let input = &buf.into_inner()[0..written];

	io::stdout().write(b"\x1b[38;5;214m").unwrap();
	io::stdout().write(input).unwrap();
	io::stdout().write(b"\n").unwrap();
	io::stdout().flush().unwrap();
}
