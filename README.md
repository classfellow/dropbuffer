## dropBuffer

>If this is so dangerous why should you use it? Because it can drastically
increase throughput by relieving pressure from the garbage collector.

>This is what's left of an attempt to allow users to manually free memory
attached to a Buffer instance. It was too precarious to do in core, so now
I'm making my efforts available here.

>https://github.com/trevnorris/buffer-dispose