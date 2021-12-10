all: giftest

giftest: giftest.c deps/gifski/target/debug/libgifski.a
	cc giftest.c -o giftest -Ideps/gifski deps/gifski/target/debug/libgifski.a -lm -ldl -pthread

deps/gifski/target/debug/libgifski.a: deps/gifski/Cargo.toml
	cd deps/gifski && cargo build

deps/gifski/Cargo.toml:
	mkdir -p deps/gifski && git clone https://github.com/ImageOptim/gifski deps/gifski
