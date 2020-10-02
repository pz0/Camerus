<img src="https://github.com/pz0/Camerus/blob/master/logo.png"></img>


<h1>Short project description</h1>
It will be an Camera Monitoring Framework written in C++.

<h2>Upcoming Features</h2>
<table>
    <th>
        <td>Feature</td><td>State</td>
    </th>
    <tr>
        <td>1</td><td>Video / Live Stream Reader</td><td>DONE</td>
    </tr>
    <tr>
        <td>2</td><td>Background subtraction</td><td>DONE</td>
    </tr>
    <tr>
        <td>3</td><td>Motion Detection</td><td>IN PROGRESS</td>
    </tr>
    <tr>
        <td>4</td><td>Objects Tracking</td><td>TODO</td>
    </tr>
    <tr>
        <td>5</td><td>Clustering Algorithms</td><td>TODO</td>
    </tr>
    <tr>
        <td>6</td><td>RestAPI / WebSocket Interface</td><td>TODO</td>
    </tr>
    <tr>
        <td>7</td><td>...</td><td>TODO</td>
    </tr>
</table>

<h2>Project Examples</h2>
<p>Background Subtraction</p>
<img src="https://github.com/pz0/Camerus/blob/master/resources/res1.gif"></img>

<h1>How to start</h1>
<p>Below is just an example how to start current version of camerus build.</p>
<ol>
    <li>Clone the project / Make a fork</li>
    <li>Start the docker build process
        <ul>
            <li>docker build -t camerus .</li>
        </ul>
    </li>
    <li>Start the docker
        <ul>
            <li>docker run -it --network=host -v [path_to_camerus_resources_directory]:/tmp/resources camerus
        </ul>
    </li>
    <li>Start camerus binary
        <ul>
            <li>./camerus/build/camerus</li>
        </ul>
    </li>
    <li>Result of camerus processing should be in [path_to_camerus_resources_directory]</li>
    <li>
</ol>

<h1>Additional info</h1>
<ul>
    <li>Feel free to create issues</li>
    <li>Contribution is welcome</li>
</ul>

